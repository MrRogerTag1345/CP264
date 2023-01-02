/**
 * -------------------------
Author:  Pierce Goulimis
ID:      210276250
Email:   goul6250@mylaurier.ca
Version  2022-10-08
 * -------------------------
 */
 
# include <stdio.h>
# include <math.h>

double solve_equation(double p, double q, double n){
	//your code here

	printf("p = %.4lf\nq = %.4lf\nn = %.4lf", p, q, n);

	double r1 = (fabs(n + p)/(M_PI * M_PI));
	double r2 = (3 * sqrt(p + q))/ floor((4 * n) - q);
	double r3 = ceil(q - p)/ log2((2 * n) - q);
	double r = r1 - r2 + r3;

	printf("\nr = %.4lf - %.4lf + %.4lf\n", r1, r2, r3);

	return r;
}



int print_product_type(short code){
	//your code here

	int successState;

	if(code == 10) {
		printf("Writing");
		successState = 1;
	} else if(code == 11) {
		printf("Computer");
		successState = 1;
	} else if(code == 20) {
		printf("Executive");
		successState = 1;
	} else if(code == 21) {
		printf("Corner");
		successState = 1;
	} else if(code == 22) {
		printf("Secretary");
		successState = 1;
	} else if(code == 23) {
		printf("Floating");
		successState = 1;
	} else if(code == 24) {
		printf("Standing");
		successState = 1;
	} else {
		//Failed
		printf("Undefined");
		successState = 0;
	}

	return successState;
}



int print_country(short code){
	//your code here

	int successState;

	switch(code) {
	case 1:
		printf("Canada");
		successState = 1;
		break;
	case 2:
		printf("USA");
		successState = 1;
		break;
	case 3:
		printf("Europe");
		successState = 1;
		break;

	default:
		printf("Undefined");
		successState = 0;


	}


    return successState;
}





int print_color(short code){
	//your code here
	int successState;

	if(code == 0) {
		printf("Black");
		successState = 1;
	} else if(code == 1) {
		printf("Grey");
		successState = 1;
	} else if(code == 2) {
		printf("Purple");
		successState = 1;
	} else if(code == 3) {
		printf("Blue");
		successState = 1;
	} else if(code == 4) {
		printf("Brown");
		successState = 1;
	} else if(code == 5) {
		printf("Green");
		successState = 1;
	} else {
		printf("Undefined");
		successState = 0;
	}


	return successState;
}





short get_code(long serial_number,char type){

	int newSerialNumber = -99;

	if(type == 'I' && serial_number < 99999999 && serial_number > 9999999)
	{
		newSerialNumber = floor(serial_number/10000);
	}
	else if(type == 'T' && serial_number < 99999999 && serial_number > 9999999)
	{
		newSerialNumber = ((serial_number % 10000) - (serial_number % 100))/100;
	}
	else if(type == 'C' && serial_number < 99999999 && serial_number > 9999999)
	{
		newSerialNumber = ((serial_number % 100) - (serial_number % 10))/10;
	}
	else if(type == 'R' && serial_number < 99999999 && serial_number > 9999999)
	{
		newSerialNumber = (serial_number % 10);
	}
	else
	{}

	return newSerialNumber;

}

void print_description(long serial_number){
	//your code here

	int product_id = get_code(serial_number, 'I');
		int type_id = get_code(serial_number, 'T');
		int color_id = get_code(serial_number, 'C');
		int country_id = get_code(serial_number, 'R');
		int booltype = 0;
		int boolcolor = 0;
		int boolcountry = 0;

		char* p_types;
		switch(type_id){
		case 10:
			p_types = "Writing";
			booltype = 1;
			break;
		case 11:
			p_types = "Computer";
			booltype = 1;
			break;
		case 20:
			p_types = "Executive";
			booltype = 1;
			break;
		case 21:
			p_types = "Corner";
			booltype = 1;
			break;
		case 22:
			p_types = "Secretary";
			booltype = 1;
			break;
		case 23:
			p_types = "Floating";
			booltype = 1;
			break;
		case 24:
			p_types = "Standing";
			booltype = 1;
			break;
		default:
			p_types = "Undefined";
			break;
		}

		char* colors;

		switch(color_id){
		case 0:
			colors = "Black";
			boolcolor = 1;
			break;
		case 1:
			colors = "Grey";
			boolcolor = 1;
			break;
		case 2:
			colors = "Purple";
			boolcolor = 1;
			break;
		case 3:
			colors = "Blue";
			boolcolor = 1;
			break;
		case 4:
			colors = "Brown";
			boolcolor = 1;
			break;
		case 5:
			colors = "Green";
			boolcolor = 1;
			break;
		default:
			colors = "Undefined";
			break;
		}

		char* countrys;
		if(country_id == 1)
		{
			countrys = "USA";
			boolcountry = 1;
		}
		else if(country_id == 2)
		{
			countrys = "Canada";
			boolcountry = 1;
		}
		else if(country_id == 3)
		{
			countrys = "Europe";
			boolcountry = 1;
		}
		else
		{
			countrys = "Undefined";
		}

		printf("Product ID = %d\nType = %s\nColor = %s\nCountry = %s\n", product_id, p_types, colors, countrys);

		if(product_id == -99 && booltype == 0 && boolcolor == 0 && boolcountry == 0){
			printf("Description not found\n");
		}
		else{

			if(booltype == 0 && boolcolor == 0 && boolcountry == 0){
				printf("An Elegant Desk ID# %d\n", product_id);
			}
			else if(booltype == 0 && boolcolor == 0 && boolcountry == 1){
				printf("An Elegant Desk ID# %d Made in %s\n", product_id, countrys);
			}
			else if(booltype == 0 && boolcolor == 1 && boolcountry == 0){
				printf("An Elegant %s Desk ID# %d\n", colors, product_id);
			}
			else if(booltype == 1 && boolcolor == 0 && boolcountry == 0){
				printf("An Elegant %s Desk ID# %d\n", p_types, product_id);
			}
			else if(booltype == 0 && boolcolor == 1 && boolcountry == 1){
				printf("An Elegant %s Desk ID# %d Made in %s\n", colors, product_id, countrys);
			}
			else if(booltype == 1 && boolcolor == 0 && boolcountry == 1){
				printf("An Elegant %s Desk ID# %d Made in %s\n", p_types, product_id, countrys);
			}
			else if(booltype == 1 && boolcolor == 1 && boolcountry == 0){
				printf("An Elegant %s %s Desk ID# %d\n", colors, p_types, product_id);
			}
			else{
				printf("An Elegant %s %s Desk ID# %d Made in %s\n", colors, p_types, product_id, countrys);
			}
		}


		return;
}

char math_game(lv, lmf, lsf, lrf, rv, rmf, rsf, rrf) {
	int counter, lcounter, rcounter;
		char winner;

		printf("Starting Math Game:\n[%ld,%d,%d,%d] vs [%ld,%d,%d,%d]\n",lv, lmf, lsf, lrf,rv, rmf, rsf, rrf);

		counter = 0;

		while(counter < 5 && lv < rv){

			printf("Round = %d\n",counter + 1);
			lcounter = 0;

			while(lcounter < lrf)
			{
				lv = lv*lmf - lsf;
				printf("L = %ld\n",lv);
				lcounter += 1;
			}
			rcounter = 0;

			while(rcounter < rrf)
			{
				rv = rv*rmf - rsf;
				printf("R = %ld\n",rv);
				rcounter += 1;
			}

			counter += 1;
		}

		printf("Closing Math Game\n");

		if(counter == 5)
		{
			winner = 'R';
		}
		else
		{
			winner = 'L';
		}

		return winner;

}