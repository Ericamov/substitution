# CS50 – Readability

## Description

This program encrypts a message using a substitution cipher based on a user-provided key.

## How it works

The program:

1. Takes a single command-line argument as the encryption key
2. Validates that the key contains exactly 26 unique alphabetic characters
3. Prompts the user to enter plaintext
4. Substitutes each letter in the plaintext with the corresponding letter from the key
5. Preserves the case of each letter (uppercase/lowercase)
6. Leaves non-alphabetic characters unchanged

## Usage

```
make substitution
./substitution KEY
```

## Example

```
./substitution YTNSHKVEFXRBAUQZCLWDMIPGJO
plaintext: Hello, World!
ciphertext: Ehbbq, Pqcbf!
```

## Concepts

- Command-line arguments
- String manipulation
- Character classification (isalpha, isupper, tolower, toupper)
- Arrays and indexing
- Loops
- Input validation
