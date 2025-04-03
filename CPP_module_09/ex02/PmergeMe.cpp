#include "PmergeMe.hpp"

// Helper functions moved outside the class
std::string trim(const std::string& s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end = s.find_last_not_of(" \t\n\r");

    if (start == std::string::npos) {
        return "";
    }
    return s.substr(start, end - start + 1);
}

bool is_number(const std::string& trimmed) {
    if (trimmed.empty()) {
        return false;
    }
    
    size_t start = 0;
    if (trimmed[0] == '+') {
        if (trimmed.length() == 1) return false;
        start = 1;
    } else if (trimmed[0] == '-') {
        return false; // Negative numbers not allowed
    }
    
    for (size_t i = start; i < trimmed.length(); i++) {
        if (!std::isdigit(trimmed[i])) {
            return false;
        }
    }
    return true;
}

// Custom compare function for pairs
struct PairCompare {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) const {
        return a.first < b.first;
    }
};

// Template implementations
template<typename Container>
PmergeMe<Container>::PmergeMe() : _data(), time(0.0) {}

template<typename Container>
PmergeMe<Container>::~PmergeMe() {}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& other) : _data(other._data), time(other.time) {}

template<typename Container>
PmergeMe<Container>& PmergeMe<Container>::operator=(const PmergeMe& other) {
    if (this != &other) {
        _data = other._data;
        time = other.time;
    }
    return *this;
}

template<typename Container>
PmergeMe<Container>::PmergeMe(char** data) : _data(), time(0.0) {
    for (int i = 1; data[i]; ++i) {
        std::string trimmed = trim(data[i]);
        if (!is_number(trimmed)) {
            throw std::runtime_error("Error: Invalid input or not a positive number");
        }
        
        long long num = 0;
        std::istringstream iss(trimmed);
        iss >> num;
        
        if (num > std::numeric_limits<int>::max()) {
            throw std::runtime_error("Error: Number exceeds integer maximum value");
        }
        
        _data.push_back(static_cast<int>(num));
    }
}

template<typename Container>
int PmergeMe<Container>::ft_stoa(const char* str) {
    std::istringstream iss(str);
    long long num;
    iss >> num;
    
    if (num > std::numeric_limits<int>::max()) {
        throw std::runtime_error("Error: Number exceeds integer maximum");
    }
    
    return static_cast<int>(num);
}

template<typename Container>
typename PmergeMe<Container>::pair_vector PmergeMe<Container>::generate_pairs(Container& data) {
    pair_vector pairs;
    for (size_t i = 0; i + 1 < data.size(); i += 2) {
        // Create pair with larger element as first
        if (data[i] > data[i + 1]) {
            pairs.push_back(std::make_pair(data[i], data[i + 1]));
        } else {
            pairs.push_back(std::make_pair(data[i + 1], data[i]));
        }
    }
    return pairs;
}

template<typename Container>
void PmergeMe<Container>::mergeSort(pair_vector& pairs) {
    // Base case
    if (pairs.size() <= 1) {
        return;
    }
    
    // Split into two halves
    size_t middle = pairs.size() / 2;
    pair_vector leftHalf(pairs.begin(), pairs.begin() + middle);
    pair_vector rightHalf(pairs.begin() + middle, pairs.end());
    
    // Recursively sort both halves
    mergeSort(leftHalf);
    mergeSort(rightHalf);
    
    // Merge sorted halves back together using custom comparator
    PairCompare comparator;
    std::merge(leftHalf.begin(), leftHalf.end(), 
               rightHalf.begin(), rightHalf.end(), 
               pairs.begin(), comparator);
}

template<typename Container>
int PmergeMe<Container>::binary_search(int target, int max) {
    int left = 0;
    int right = max;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid potential overflow
        
        if (_data[mid] == target) {
            return mid;
        } else if (_data[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return left; // Position where target should be inserted
}

template<typename Container>
std::vector<int> PmergeMe<Container>::generate_indexes(size_t size) {
    std::vector<int> indices;
    
    // Calculate Jacobsthal numbers up to what we need
    std::vector<int> jacobsthal(size + 1);
    jacobsthal[0] = 0;
    jacobsthal[1] = 1;
    
    int last_jacobsthal = 1;
    
    for (size_t i = 2; indices.size() < size; ++i) {
        // Calculate next Jacobsthal number: J(n) = J(n-1) + 2*J(n-2)
        jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
        
        // Skip first element (we already have it in the chain)
        if (i > 2) {
            indices.push_back(jacobsthal[i]);
        }
        
        // Add indices between current and last Jacobsthal number in descending order
        for (int j = jacobsthal[i] - 1; j > last_jacobsthal; --j) {
            indices.push_back(j);
        }
        
        last_jacobsthal = jacobsthal[i];
    }
    
    return indices;
}

template<typename Container>
void PmergeMe<Container>::insert_elements(pair_vector& pairs, std::vector<int>& insertion_indices, int last_element) {
    // Insert elements according to the Jacobsthal sequence
    for (size_t i = 0; i < insertion_indices.size(); ++i) {
        int idx = insertion_indices[i] - 1;
        
        // Skip if index is out of bounds
        if (idx >= static_cast<int>(pairs.size())) {
            continue;
        }
        
        // Find target value position in the current sorted list
        int target_value = pairs[idx].first;
        typename Container::iterator pos = std::find(_data.begin(), _data.end(), target_value);
        
        if (pos == _data.end()) {
            continue;
        }
        
        int target_pos = std::distance(_data.begin(), pos);
        
        // Find insertion position using binary search
        int insert_pos = binary_search(pairs[idx].second, target_pos - 1);
        
        // Insert the smaller element from the pair
        _data.insert(_data.begin() + insert_pos, pairs[idx].second);
    }
    
    // Insert the last element if size was odd
    if (last_element != -1) {
        int pos = binary_search(last_element, _data.size() - 1);
        _data.insert(_data.begin() + pos, last_element);
    }
}

template<typename Container>
void PmergeMe<Container>::sort() {
    // Start timing
    std::clock_t start_time = std::clock();
    
    // Handle empty or single-element case
    if (_data.size() <= 1) {
        time = static_cast<double>(std::clock() - start_time) / CLOCKS_PER_SEC;
        return;
    }
    
    // Store last element if odd number of elements
    int last_element = -1;
    if (_data.size() % 2 != 0) {
        last_element = _data.back();
        _data.pop_back();
    }
    
    // Generate and sort pairs
    pair_vector pairs = generate_pairs(_data);
    mergeSort(pairs);
    
    // Clear data and start with the small element from first pair
    _data.clear();
    if (!pairs.empty()) {
        _data.push_back(pairs[0].second);
        
        // Add all large elements to form main chain
        for (size_t i = 0; i < pairs.size(); ++i) {
            _data.push_back(pairs[i].first);
        }
        
        // Generate insertion sequence based on Jacobsthal numbers
        std::vector<int> insertion_indices = generate_indexes(pairs.size());
        
        // Insert remaining elements according to Ford-Johnson algorithm
        insert_elements(pairs, insertion_indices, last_element);
    } else if (last_element != -1) {
        // If we only had one element originally
        _data.push_back(last_element);
    }
    
    // Calculate elapsed time
    time = static_cast<double>(std::clock() - start_time) / CLOCKS_PER_SEC;
}

template<typename Container>
void PmergeMe<Container>::print_container() const {
    for (size_t i = 0; i < _data.size(); ++i) {
        std::cout << _data[i];
        if (i < _data.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

// Container type name helpers
template<typename T>
std::string get_container_name();

template<>
std::string get_container_name<std::vector<int> >() {
    return "std::vector";
}

template<>
std::string get_container_name<std::deque<int> >() {
    return "std::deque";
}

template<typename Container>
void PmergeMe<Container>::print_time() const {
    std::cout << "Time to process a range of " << _data.size() 
              << " elements with " << get_container_name<Container>() 
              << ": " << time << " sec" << std::endl;
}

// Explicit template instantiations
template class PmergeMe<std::vector<int> >;
template class PmergeMe<std::deque<int> >;