#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>

template <typename T>
T geometric_mean(T array[], const int size)
{
        T product = 1;

        for (int i = 0; i < size; i++)
        {
            product *= array[i];
        }

        T result = pow(product, 1.0 / size);
        return result;
}

template <>
std::string geometric_mean(std::string array[], const int size);
char geometric_mean(char array[], const int size)
{
    throw std::invalid_argument("Не можна використовувати string.");
}

int main()
{
    setlocale(LC_ALL, "Ukrainin");
    try {
        int arr[] = { 1, 1, 3, 4, 5 };
        int result = geometric_mean(arr, 5);
        std::cout << "Geometric Mean: " << result << std::endl;

        double arr1[] = { 2.5, 4.7, 6.3, 8.1 };
        double result1 = geometric_mean(arr1, 4);
        std::cout << "Geometric Mean: " << result1 << std::endl;

        std::string arr2[] = { "hello", "world" };
        std::string result2 = geometric_mean(arr2, 2);
        std::cout << "Geometric Mean: " << result2 << std::endl;

        char arr3[] = { 'a', 'b', 'c'};
        char result3 = geometric_mean(arr3, 3);
        std::cout << "Geometric Mean: " << result3 << std::endl;

    }
    catch (const std::exception& e) {
        std::cout << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}