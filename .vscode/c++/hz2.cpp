#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "sched.h"


const int MAX_COUNT = 10;

sched* arr_sched[MAX_COUNT];

int main()
{
	setlocale(LC_ALL, "Russian");
	int l = -1;
	while (l != 0)
	{
		puts("\n¬‚Â‰ËÚÂ\n"
			"1 - —ÓÁ‰‡ÌËÂ ‡ÒÔËÒ‡ÌËˇ\n"
			"2 - œÓËÒÍ\n"
			"3- ¬˚‚Ó‰\n"
			"0 - ¬˚ıÓ‰\n");
		scanf("%d", &l);
		getchar();
		switch (l)
		{

		case 1:
		{
			if (sched::GetCount() < MAX_COUNT - 1)
			{
				puts("\n¬‚Â‰ËÚÂ ‰ÂÌ¸ ÌÂ‰ÂÎË\n");
				int our_day;
				scanf("%d", &our_day);

				if (our_day > 7 or our_day < 1)
				{
					puts("ÕÂÍÓÂÍÚÌ˚È ‰ÂÌ¸");
					break;
				}
				puts("\n¬‚Â‰ËÚÂ ÌÓÏÂ Ô‡˚\n");
				int our_pare_nom;
				scanf("%d", &our_pare_nom);
				puts("\n¬‚Â‰ËÚÂ ÔÂ‰ÏÂÚ\n");
				char our_obj[20];
				scanf("%s%*c", &our_obj);
				puts("\n¬‚Â‰ËÚÂ ÔÂÔÓ‰‡‚‡ÚÂÎˇ\n");
				char our_teacher[20];
				scanf("%s%*c", &our_teacher);
				puts("\n¬‚Â‰ËÚÂ ÚËÔ Ô‡˚\n");
				char our_type[50];
				scanf("%s%*c", &our_type);
				getchar();
				arr_sched[sched::GetCount() - 1] = new sched(our_day, our_pare_nom, our_obj, our_teacher, our_type);
			}
			else
			{
				puts("ÃÂÒÚ‡ ÌÂÚ");
			}
			break;
		}
		case 2:
		{
			if (sched::GetCount() >= 2)
			{
				puts("¬‚Â‰ËÚÂ ‰ÂÌ¸ ÌÂ‰ÂÎË");
				int our_day;
				scanf("%d", &our_day);
				Find(arr_sched, our_day, sched::GetCount());
			}
			break;
		}
		case 3:
		{
			puts("");
			for (int i = 0; i < sched::GetCount(); i++)
			{
				arr_sched[i]->Print();
			}
			break;
		}
		case 0:
		{
			break;
		}
		}
	}
	return 1;
}
