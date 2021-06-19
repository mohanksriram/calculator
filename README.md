# A Scientific Calculator API with support for command-line input.

### Inputs
- A single line of string containing the expression to be parsed in either infix or postfix form.

### Supported Operands
- +, -, *, /, log, ln, sin, cos, tan, ctan

### Supported Constants
Pi, e

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

![calculator](https://user-images.githubusercontent.com/22681121/122637093-76ec2e00-d10a-11eb-841f-277a41f11efe.png)

