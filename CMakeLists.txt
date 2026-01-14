cmake_minimum_required(VERSION 4.0)
project(claude)

set(CMAKE_CXX_STANDARD 14)

add_executable(claude
        examples/01_hello_world.cpp
        examples/02_calculator.cpp
        examples/03_fizzbuzz.cpp
        examples/04_prime_checker.cpp
        examples/05_bank_account.cpp
        examples/06_student_system.cpp
        examples/07_vector_operations.cpp
        examples/08_word_counter.cpp
        examples/09_smart_pointers.cpp
        examples/10_lambda_examples.cpp
        progress/hello.cpp
        progress/chapter2.cpp
)
