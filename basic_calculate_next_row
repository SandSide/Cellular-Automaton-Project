
// for every column in the enxt row
for (int i = 0; i <maxColumn; i++)
{
	
	if(i == 0)
	{

		// checking previous row to find out what will happen to the first box (column) in the new row
		String prevBox = array[previousRow - 1, maxColumn];
		String currBox = array[previousRow - 1, i];
		String nextBox = array[previousRow - 1, i+1];


	}
	else if (i = maxColum)
	{

		// checking previous row to find out what will happen to the last box (column) in the new row
		String prevBox = array[previousRow - 1, i-1];
		String currBox = array[previousRow - 1, i];
		String nextBox = array[previousRow - 1, 0];

	}
	else
	{

		// checking previous row to find out what will happen to the  box (column) in the new row

		String prevBox = array[previousRow - 1, maxColumn];
		String currBox = array[previousRow - 1, i];
		String nextBox = array[previousRow - 1, i+1];


	}

	// add strings together to recieve a pattern e.g. 010, 110, 011 etc.
	boxPattern = prevBox + currBox + nextBox;

	// compare the pattern to recieve the rule
	case (boxPattern)
	{

			rule[0,0] then array[currentRow, i] = rule [1,0];

			rule[0,1] then array[currentRow, i] = rule [1,1];

			rule[0,2] then array[currentRow, i] = rule [1,2];

			rule[0,3] then array[currentRow, i] = rule [1,3];

			rule[0,4] then array[currentRow, i] = rule [1,4];

			rule[0,5] then array[currentRow, i] = rule [1,5];

			rule[0,6] then array[currentRow, i] = rule [1,6];

			rule[0,7] then array[currentRow, i] = rule [1,7];

	}

}