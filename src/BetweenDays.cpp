/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node
{
	int data;
	struct node *next;
};

int between_days(struct node *date1head, struct node *date2head)
{
	int val=0,var,date1=0,mon1=0,year1=0,date2=0,mon2=0,year2=0;
	int result=0,res_years,res_days,res_months;
	for (var = 0;var<8; var++)
	{
		val = date1head->data;
		date1head = date1head->next;
		if (val < 2)
		{
			date1 = date1 * 10 + val;
		}
		if (val > 1 && val < 4)
		{
			mon1 = mon1 * 10 + val;
		}
		if (val > 3 && val < 8)
		{
			year1 = year1 * 10 + val;
		}
	}
	for (var = 0; var<8; var++)
	{
		val = date2head->data;
		date2head = date2head->next;
		if (val < 2)
		{
			date1 = date1 * 10 + val;
		}
		if (val > 1 && val < 4)
		{
			mon1 = mon1 * 10 + val;
		}
		if (val > 3 && val < 8)
		{
			year1 = year1 * 10 + val;
		}
	}
	if (mon2 > mon1)
	{
		res_years = year2 - year1;
		res_months = mon2 - mon1;
		res_days = date2 - date1;
		result = res_days + (res_months * 31) + (res_years * 365);
	}
	else if (mon2 == mon1)
	{
		if (date2 > date1)
		{
			res_years = year2 - year1;
			res_months = 0;
			res_days = date2 - date1;
			result = res_days + (res_years * 365);
		}
		else if (date2 == date1)
		{
			res_years = year2 - year1;
			result = (res_years)* 365;
		}
		else
		{
			res_years = year2 - year1;
			res_days = date2 - date1;
			result = res_days + (res_years * 365);
		}
	}
	else if (mon1 > mon2)
	{
		res_years = year2 - year1;
		res_months = mon1 - mon2;
		res_days = date2 - date1;
		result = res_days - (res_months * 31) + (res_years * 365);
	}
	if (result>0)
	{
		return result;
	}
	else if (result < 0)
	{
		return NULL;
	}
}