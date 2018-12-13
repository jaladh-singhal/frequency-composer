#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>

#define MAX 1000
void line(int x)
{
	int i;
	for(i=1;i<=x;i++)
		printf("-");
	printf("\n");
}

void cleanBuffer()	//to clean upto newline charcter in buffer
{
	int c;
	while((c=getchar())!='\n' && c!=EOF);
}

int main(void)
{
	//Data elements-------------------------------------------------------------------
	char c,cont='y',*notes,input[MAX];
	int i,j,option;
	float oct4freq[7]={261.626,293.665,329.628,349.228,391.995,440.000,493.883};
	float oct4Freq[5]={277.183,311.127,369.994,415.305,466.164};
	int octSeq[7]={4,100,0,1,100,2,3};
	
	char notesCollection[][MAX]={
		"ccggaag ffeeddc ggffeed ggffeed ccggaag ffeeddc",	//Twinkle
		"ddedgF ddedag dddbgFe ccbgag",		//H Bday-1
		"ccdcfe ccdcgf cccafed AAafgff ccdcfe ccdcgf cccafed AAafgff",	//H Bday-2
		"begFebaF egFDfb  begFebdCc GcbAAge gbgbgcbA FgbAAbb gbgbgdCc GcbAAge",			//HP Theme
		"eFGFeeFF  eeFGFeeFC CeFGeeFF eFGFeFC FGbGFeF CeFGFeFC CCCCeFGCeFF eFGFeFC  CCeeFFGG eFGFeFC"	//Shape of You
	};
	int numNotesColl=sizeof(notesCollection)/(sizeof(char)*MAX);
	//----------------------------------------------------------------------------------
	
	while(cont=='y')
	{
	system("cls");
	line(70);
	printf("\t\tWELCOME to <<< FREQUENCY COMPOSER >>>\n\nIt is used to compose Sound by only using Changes in Frequency!!!\n");
	line(70);
	printf("\nChoose what would you like to enjoy:\n1.-> Create a Sound Show on basis of your Input\n2.-> Listen to some Pre-existing Music\n3.-> Compose Music using Musical Notes\n\n");
	printf("Input the Option No.: ");
	gets(input);
	option=atoi(input);	//Validating integer input
	printf("\n");
	if(option==1)
	{
		int *num=malloc(1*sizeof(int)),size;
		i=0,j=1;	//For capturing two digit no.s out of the input string - i to move in num array, j to toggle b/w 1st & 2nd digit
		printf("\nInput a string made of Digits only:\n(Longer the string, longer will be the Sound Show)\n");
		while((c=getchar())!='\n')
		{
			if(c<'0' || c>'9')
			{
				printf("Only Digits are allowed! Input has terminated with 1st occurance of Non-Digit character.\n");
				cleanBuffer();
				break;
			}
			if(j) //1st Digit
			{
				num=realloc(num,(1+i)*sizeof(int));
				num[i]=(c-'0')*10;
			}
			else //2nd Digit
			{
				num[i]+=(c-'0');
				i++;
			}
			j=(j+1)%2;	//toggle j (1 or 0)
		}
		//Determining size of array
		if(j)
			size=i;
		else
			size=i+1;
		if(size)	//Validating that num array (of 2 digit no.s) is not empty
		{
		int mode,f1,f2,rLow,rHigh;
		printf("\nThe Frequencies will now be calculated by extracting 2 digits numbers \nfrom the input string!\n\nMeanwhile, select one from the available modes:\n");
		printf("1.-> Customized Range\n2.-> Low Frequency (0-1,000)\n3.-> High Frequency(12,000-18,000)\nANY NO.-> General\n\n");
		printf("Input the Mode No.: ");
		gets(input);
		mode=atoi(input);	//Validating integer input
		
		switch(mode)
		{
			case 1:
				printf("\nInput max. value (must be between 100 and 20,000): ");
				gets(input);
				rHigh=atoi(input);	//highest range	
				if(rHigh>=20000 || rHigh<=100)	//When invalid input
				{
					printf("Invalid Input! Taking it =20,000\n");
					rHigh=20000;
				}
				printf("\nInput min. value (must be between 0 and (max. value - 100)): ");
				gets(input);
				rLow=atoi(input);	//lowest range	
				if(rLow<=0 || rLow>=rHigh-100)	//When invalid input
				{
					printf("Invalid Input! Taking it =0\n");
					rLow=0;
					sleep(2);
				}
				break;
			case 2:
				rLow=0;
				rHigh=1000;
				break;
			case 3:
				rLow=12000;
				rHigh=18000;
				break;
			default:
				rLow=0;
				rHigh=18000; //>18,000 (upto 20,000) are very feeble
				break;
		}
		
		system("cls");
		f1=(rHigh-rLow)/100;	//Factor1 = Difference in ranges scaled down to 100
		f2=rLow;	//Factor2 = The equivalent of zero in new scale
		line(70);
		printf("GET READY FOR THE SOUND SHOW CREATED BY YOU!...\n");
		line(70);
		printf("\n");
		sleep(2);
		for(i=0;i<size;i++)
		{
			int barMax=num[i]*0.70;		//Scaling 0-100 to 0-70 (Max. characters that can be printed in a line = ~75)
			int freq=num[i]*f1+f2; 		//Scaling 0-100 to rLow-rHigh Hz
			printf("%5d Hz  ",freq);
			for(j=1;j<=barMax;j++)	//Drawing bar graph
				printf("%c",220);	//ASCII-220 is bottom half BLOCK (Extended ASCII char)
			Beep(freq,800);	//Play the beep of coressponding frequency
			printf("\n");
		}
		printf("\n\nNow, How do your ears feel?\t...LOL :P\n");
		}
	}
	else if(option==2 || option==3)	//Both handle musical notes
	{
		if(option==2)
		{
			int noteNum;
			printf("Choose one of these:\n1.-> Twinkle Twinkle\n2.-> Happy Birthday-1\n3.-> Happy Birthday-2\n4.-> Harry Potter Theme\n5.-> Shape of You\n\n");
			printf("Input the Option No.: ");
			gets(input);
			noteNum=atoi(input);
			if(noteNum<=0 || noteNum>numNotesColl)
			{
				printf("Invalid input! Taking it =1\n");
				noteNum=1;
				sleep(2);
			}
			notes=&notesCollection[noteNum-1][0];
		}
		else
		{
			char noteStr[MAX];
			printf("Let\'s Guide you first:\nIn Music- A,B,C,D,E,F,G are Normal Notes  and  A#,C#,#D,#F,#G are Sharp Notes\nEach note has an Octave No. from 1 to 7\nHere Octave No. 4 will be used\n\n");
			printf("Input Example-\nTo represent\t\t\t\tInput in this way\nD D E D G F#\nD D E D A G\nD D D B G F# E  ---------------->  ddedgF ddedag dddbgFe ccbgag\nC C B G A G\n\n");
			printf("Input the Notes to Compose Music:\n");
			gets(noteStr);
			while(1)		//Validating Input
			{
				for(i=0;noteStr[i]!='\0';i++)
				{
					char z=noteStr[i];
					if(!(z>='a' && z<='g') && !(z>='A' && z<='G' && z!='B' && z!='E') && z!=' ')
					{
						printf("\nInvalid Input! \'%c\' is not allowed\n",z);
						break;
					}
				}
				if(i==strlen(noteStr))
					break;
				printf("Input the Notes again:\n");
				gets(noteStr);
			}
			notes=&noteStr[0];	
		}
		
		int size;
		float *m=malloc(sizeof(float));
		i=0;
		while((c=notes[i])!='\0')	//Converting notes into frequencies & storing into array m
		{
			m=realloc(m,(1+i)*sizeof(float));
			if(c>='a' && c<='g')	//Fetching frequency value corresponding to normal notes
				m[i]=oct4freq[(c-'a'+5)%7];	
			else if(c>='A' && c<='G')	//Fetching frequency value corresponding to sharp notes
				m[i]=oct4Freq[octSeq[c-'A']]; //octSeq is array for sharp notes' indices
			else if(c==' ') 
				m[i]=0;	//Storing 0 freq for pauses (time-gaps in music)
			i++;
		}
		size=i;
		
		system("cls");
		line(70);
		printf("GET READY TO ENJOY THE MUSIC!...\n");
		line(70);
		printf("\n");
		sleep(2);
		char noteLtr[3];	//String for Note Letter
		
		for(i=0;i<size;i++)
		{
			int barMax=m[i]*0.07;		//Scaling 0-1000 to 0-70 (Coz Notes Octave-3 or 4's Frequency range 200-800)
			//Preparing noteLtr string-------------
			if(notes[i]>='a' && notes[i]<='g')
			{
				noteLtr[0]=notes[i]-('a'-'A');
				noteLtr[1]='\0';
			}
			else if(notes[i]>='A' && notes[i]<='G')
			{
				noteLtr[0]=notes[i];
				noteLtr[1]='#';
				noteLtr[2]='\0';
			}
			else if(notes[i]==' ')
				strcpy(noteLtr," ");
				
			printf("%2s  ",noteLtr);
			for(j=1;j<=barMax;j++)	//Drawing bar graph
				printf("%c",220);
			Beep(m[i],450);	//Play Beep
			printf("\n");
		}
		printf("\n\nThat's how we can play with Numbers!\nUnlike original music, this music was composed by the changes \nonly in frequency values!\n");
	}
	else
		printf("Invalid Input!\n");
	
	line(70);
	printf("Wanna continue the Fun? - (y/n): ");	//Re-directing to the 1st menu
	cont=getchar();
	cleanBuffer();
	}
	line(70);
	printf("Thank You!\nBye-Bye!!!\n");	//Terminating the program
	line(70);
	
return 0;
}
