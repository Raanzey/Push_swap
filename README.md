# Push_swap

This project implements a sorting algorithm using two stacks (`a` and `b`) with a restricted set of operations. The goal is to sort numbers with the smallest number of moves possible.  

Key concepts:
- Stack manipulation
- Sorting algorithms
- Complexity optimization

### Algorithms Used
- **Greedy algorithm** for efficient moves
- **Turkish Algorithm** (Türk algoritması): A strategy designed by Turkish students at 42 that focuses on dividing the problem into groups (chunks), pushing numbers to the second stack in ranges, and then reinserting them into the main stack in sorted order. This method reduces the number of operations significantly and provides a practical balance between complexity and efficiency.

- This approach is easy to implement and scores perfectly in the 42 evaluation system. For an in-depth explanation, see [“Push Swap — A journey to find most efficient sorting algorithm” by A. Yigit Oğun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).
