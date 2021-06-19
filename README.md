# A Scientific Calculator API with support for command-line input.

### Dependencies
- Bazel: Find the installation instructions [here](https://docs.bazel.build/versions/main/install-ubuntu.html).

### Build Instructions
```
//Application
bazel build //calculator:calculator

//Tests
bazel test $(bazel query //...)

```

### Usage
```
bazel-bin/calculator/calculator
```
- Select the mode of the input expression: 1. Infix, 2. Postfix
- Enter the expression to be evaluated.
- Observe the output on the screen.

![calculator](https://user-images.githubusercontent.com/22681121/122637805-3a223600-d10e-11eb-8f0a-eae1d1e845a7.gif)

### Inputs
- A single line of string containing the expression to be parsed in either infix or postfix form.

### Supported Operands
- +, -, *, /, log, ln, sin, cos, tan, ctan

### Supported Constants
Pi, e
