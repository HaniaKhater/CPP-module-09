# **REVERSE POLISH NOTATION (RPN)**

## Errors Management
* Anything other than digits, paces, matematical operators.
* More operators than (operands - 1)
* More operands than (operator + 1)
* operator other than `+`, `-`, `*`, & `/`
* dividing by 0<br>
<br>All of these errors are thoroughly tested by using the testerRPN.sh script like this:
```
bash testerRPN.sh
```
## Live Calculations:
To evaluate the expression, you need to loop through the input:

* When you encounter a number:<br>
        1. save it by pushing it into `nbStack`.
* When you encounter an operator:<br>
        1. pop the first two numbers from `nbStack`.<br>
        2. Perform the operation on these two numbers.<br>
        3. Push the result back to the `nbStack`.<br>

➜ If there is more than one number left on the nbStack after the loop, the input expression is in an incorrect format

## Examples

Input:          **[ 2 1 + 3 * ]**<br>
Output:         **9**<br>
Explanation:    **((2 + 1) * 3)** = 9<br>
<br>
Input:          **[ 4 13 5 / + ]**<br>
Output:         **6**<br>
Explanation:    **(4 + (13 / 5))** = 6<br>
<br>
Input:          **[ 10 6 9 3 + -11 * / * 17 + 5 + ]**<br>
Output:         **22**<br>
Explanation:    **((10 * (6 / ((9 + 3) * -11))) + 17) + 5** <br>
                = **((10 * (6 / (12 * -11))) + 17) + 5** <br>
                = **((10 * (6 / -132)) + 17) + 5** <br>
                = **((10 * 0) + 17) + 5** <br>
                = **(0 + 17) + 5 = 17 + 5** <br>
                = **22**<br>
<br>
![Image](https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/Reverse_Polish_Notation_Stack_Example.jpg/800px-Reverse_Polish_Notation_Stack_Example.jpg?20140514181604)
