/* Checks whether a tic-tac-toe board is completely filled.	*/
int filled(char ttt_brd[3][3]) /* input - tic-tac-toe board	*/
{
  int r, c, /* row and column subscripts */	
  for (r = 0; r < 3; ++r)
    for (c = 0; c < 3; ++c)
      if (ttt_brd[r][c] == ' ') 
        return 0;  /* return 0: false , 9x9 matrix was not completely full. No need to check remaining cells */ 
	/* if you checked all cells and no blank was found, then the matrix is full so return 1: true */ 
  return 1;
}
