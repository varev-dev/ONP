# Reverse Polish notation

## About
Project that takes expression as an input with operators such as:

```
+, -, *, /, if(a,b,c), max(var...), min(var...), ()
```

if - depends on 'a' parameter, returns b if a greater than 0, otherwise returns c

max, min - returns maximum/minimum value from all provided in parentheses

## Instruction
1. Check operational chars defined as DIVIDER, SEPARATOR & END in `includes/Reader.h`.
2. Enter amount of expressions (max <b>2</b><sup>16</sup>).
3. Enter expression according to the defined formatting.
4. Repeat step 3 until you have entered all the expressions.
+ You can enter all expressions at once.

## Output
The program prints out every single operation, and at the very end, after each operation is completed it returns the final value or `ERROR`.

When `ERROR` occurs, no further operations will be performed on this expression, and the program is going to work with next one.