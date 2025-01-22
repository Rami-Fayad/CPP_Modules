#include "Serializer.hpp"

int main()
{
    // Creating a Data object
    Data data("Hello, World!", 42);

    // Serialize the pointer to the data object
    unsigned long raw = Serializer::serialize(&data);

    // Deserialize the pointer back
    Data *deserializedData = Serializer::deserialize(raw);

    // Check if the original pointer is equal to the deserialized pointer
    if (&data == deserializedData)
    {
        std::cout << "Success: The original pointer and the deserialized pointer are the same!" << std::endl;
    }
    else
    {
        std::cout << "Failure: The pointers are different!" << std::endl;
    }

    return 0;
}
