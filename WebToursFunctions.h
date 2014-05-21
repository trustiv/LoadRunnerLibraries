char *TableCapture()
{
	// Capture the table data with a regular expression
	web_reg_save_param_regexp (
	    "ParamName=tableData",
	    "RegExp=<td><select name=\"(.*\n)*?(</select></td>)",
	    "Group=0",
	    "Ordinal=All",
		SEARCH_FILTERS,
	    "RequestUrl=*.*",
		LAST );
}
char *ReturnTableCapture(int tableI)
{
int i, tableCount;
char tableParam[1000];

// Grab the number of captures found from 'TableCapture();'
tableCount = atoi(lr_eval_string("{tableData_count}"));

	// Iterative loop for 'tableCount'
	for (i = 1; i <= tableCount; i++) 
	{
	    // Save the captured data to tableParam, for saving to an array
	    sprintf(tableParam, lr_eval_string("{tableData_%d}"), i);
	    
	    // Print the captured data and the loop comparison to the Output/Replay log
	    //lr_output_message("i:[%d] | Tablei:[%d]", i, tableI);
	    //lr_output_message("\r\nValue of %s[%d]:\r\n%s", tableParam, i, lr_eval_string(tableParam));
	    
	    // If the table requested is the same as the tableData_'count'
	    if (tableI == i)
	    {
	    	// Break the current loop, and return the current 'tableParam'
	    	break;
	    }
	}
	return lr_eval_string(tableParam);
}