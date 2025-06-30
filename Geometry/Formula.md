###  Point Location Relative to Line

Given points: 
```math 
p_1 = (x_1, y_1), p_2 = (x_2, y_2) , p_3 = (x_3, y_3)   
```

Use the formula:

```math
\text{val} = (x_2 - x_1)(y_3 - y_1) - (y_2 - y_1)(x_3 - x_1)
```

Interpretation:
1. If val > 0 ---> p3 is **left** side of the line p1 to p2
2. If val <> 0 ---> p3 is **right** side of the line p1 to p2
3. If val = 0 ---> p3 is **on the line** p1 to p2
 