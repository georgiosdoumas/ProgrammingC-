/* Checks whether a tic-tac-toe board is completely filled.	*/
int filled(char ttt_brd[3][3]) /* input - tic-tac-toe board	*/
{
  int r, c, /* row and column subscripts */	
  for (r = 0; r < 3; ++r)
    for (c = 0; c < 3; ++c)
      if (ttt_brd[r][c] == ' ')  //if you find a blanck cell ... 
        return 0;  /*   ...3x3 matrix was not completely full. No need to check remaining cells */ 
	/* if you checked all cells and no blank was found, then the matrix is full so return 1: true */ 
  return 1;
}
// This is a better inplementation than the book.  Here is what the book has on page 416 : 
/* ************************
int filled(char ttt_brd[3][3]) 
{
  int r, c, ans;    // an extra variable , ans , so more memory will be required 
  ans = 1;   // Assumes board is filled until blank is found	
  for (r = 0; r < 3; ++r)
    for (c = 0; c < 3; ++c)
      if (ttt_brd[r][c] == ' ') 
        ans = 0;  // Keep checking all cells, waist of time!  
	
  return (ans);  // after wasting time to finish the nested for-loop, return the final value of ans 
}
************************************ */
