#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>


int main (int argc, char *argv[]){

	const char* short_options = "xyz:";

	const struct option long_options[] = {
		{"xlong",no_argument,NULL,'x'},
		{"ylong",no_argument,NULL,'y'},
		{"zlong",required_argument,NULL,'z'},
		{NULL,0,NULL,0}
	};

	int rez;
	int option_index = -1;

    int flag_x=0;
    int flag_y=0;
    int flag_z=0;

	while ((rez=getopt_long(argc,argv,short_options,
		long_options,&option_index))!=-1){

		switch(rez){
			case 'x': {
                if (flag_x == 0) {
                    flag_x=1;
				    printf("Arg: \"x\", ");
                    if(option_index<0)
                        printf("type: short\n");
                    else
                        printf("type: long\n");
                }
				break;
			};
			case 'y': {
                if (flag_y == 0) {
                    flag_y=1;
				    printf("Arg: \"y\", ");
                    if(option_index<0)
                        printf("type: short\n");
                    else
                        printf("type: long\n");
                }
				break;
			};
	
			case 'z': {
                if (flag_z == 0) {
                    flag_z=1;
				    printf("Arg: \"z\", ");
                    if(option_index<0)
                        printf("type: short, ");
                    else
                        printf("type: long, ");
				    printf("value: %s\n",optarg);
                }
				break;
			};
			case '?': default: {
				printf("Found unknown option\n");
				break;
			};
		};
        option_index = -1;

	};
	return 0;
};
