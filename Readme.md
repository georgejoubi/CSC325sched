# Task Scheduling

You have _n_ tasks to perform. Each task _i_ has a duration _t<sub>i</sub>_ , a deadline _d<sub>i</sub>_ and if you perform the taks by the 
deadline you earn a profit _p<sub>i</sub>_, otherwise you don't get any profit. As an example

|Name | Duration | Deadline | Profit|
|---  |  ---     |     ---   |    ---|
|A    | 1        | 2        | 70|
|B    | 1        | 1        | 23|
| C    | 1      | 2         | 27 |
| D     | 1     | 1         |25 |
|E      | 1     |3          |15|


Clearly in the above example, to earn the maximum profit you would schedule task 
C from 0 to 1 then task A from 1 to 2 and finally task E from 2 to 3. Your total
earning would be 112

# Gready Strategy (65 pts)

When the duration of all tasks is one unit time, as in the example above, there is
an optimal greedy strategy. Find the optimal greedy strategy and write your code 
in the function `greedy_solve` in  file sched.cpp. The function `greedy_solve`
should return the list (as a vector of strings) of the tasks that will run by the deadline
Note that you can define any extra functions you want or gobal variables but the 
main function should remain without modifications. Further the function greedy_solve
should retain the same signature.

# Dynamic Programming (25 pts)

When the duration is not a unit time for all the tasks the greedy strategy does not
always give the optimal solution. Design a dynamic programming strategy to obtain
the optimal solution. Write your code in the function `dp_solve` in the same file.
As in the previous note you should not modify main or the signature of the functions.
The function `dp_solve` should return the profit table for the optimal solution.

# Dynamic Programming Solution (10pts)

Add a function that returns the actual tasks scheduled to run obtained from the 
optimal table 





