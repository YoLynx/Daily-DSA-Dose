// https://leetcode.com/submissions/detail/1535363314/


// Here we tried to look for each col and tried to fill the Queen in each row and then check if it is safe to place the Queen in that cell or not.
// If it is safe then we will place the Queen in that cell and then move to the next row and try to place the Queen in the next row.
// We are using a hash map to keep track of the cells which are safe to place the Queen and which are not.
// We will remove the Queen if the recursion doesnt work out and then try to place the Queen in the next cell.
// We are using 3 hash maps to keep track of the cells which are safe to place the Queen.
// Time Complexity -> O(n! * n) and Space Complexity -> O(n! * n).
// If we just want the number of distinct solutions we can make use of a variable count and increment it whenever we get a solution.
