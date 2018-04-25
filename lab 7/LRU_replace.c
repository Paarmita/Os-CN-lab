// LRU replacement algorithm

#include <stdio.h>

void main() {
	int pages[100];
	int frames[20];
	int no_of_frames = 0;
	int i, j, min=0, pos=0;
	int no_of_pages = 0;
	int faults=0;
	int counter=0, flag1=0, flag2=0;
	int time[20] = {-1};
	
	for(j=0; j<20; j++)
		frames[j] = -1;
	printf("Number of frames: ");
	scanf("%d", &no_of_frames);
	
	
	printf("\nNumber of pages: ");
	scanf("%d", &no_of_pages);
	printf("Sequence of page references: ");
	for(i=0; i<no_of_pages; i++) {
		scanf("%d", &pages[i]);
	}
	
	for(i=0; i<no_of_pages; i++) {
		flag1 = 0;
		flag2 = 0;
		for(j=0; j<no_of_frames; j++) {
			if(frames[j] == pages[i]) {
				flag1 = 1;
				counter++;
				time[j] = counter;
				//printf("Yes");
				break;
			}
		}
		if(flag1 == 0) {
			//printf("Yes");
			for(j=0; j<no_of_frames; j++) {
				if(frames[j] == -1) {
					frames[j] = pages[i];
					counter++;
					time[j] = counter;
					faults++;
					flag2 = 1;
					break;
				}
			}
		}
		if(flag1 == 0 && flag2 == 0) {
			min = time[0];
			pos = 0;
			for(j=1; j<no_of_frames; j++) {
				if(min > time[j]) {
					min = time[j];
					pos = j;
				}
			}
			counter++;
			frames[pos] = pages[i];
			time[pos] = counter;
			faults++;
		}
		printf("%d: [", pages[i]);
		for(j=0; j<no_of_frames-1; j++) {
			if(frames[j] != -1)
				printf("%d|", frames[j]);
			else
				printf("|"); 
		}
		if(frames[no_of_frames-1] != -1)
			printf("%d]", frames[no_of_frames-1]);
		else
			printf("]");
		if(flag1 == 0)
			printf("  F\n");
		else
			printf("\n");
	}
	printf("Number of faults: %d\n", faults);
	printf("Miss rate: %f\n", (faults*1.0)/no_of_pages);
}

