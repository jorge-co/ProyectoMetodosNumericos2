#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<windows.h>
#define max 30

void presentacion(void);
void subRutina(int, double[], double[], int);
void backMenu(double [], double [], int, int);
int numPuntos(void);
void leerTabla(double [], double [], int, int, int);
void corregir(double[], double[], int, int, int);
void corregirSimp(double[], double[], int, int, int);
int askDato(double[], double[], int);
void tipoMetodo(double[], double[], int, int, int);
void salir(void);
void incorrecto(void);
void newton(double[], double[], int, int);
void menuNewt (int*, double[], double[], int, int);
void primerSistema(void);
void segundoSistema(void);
void tercerSistema(void);
void cuartoSistema(void);
bool ordenar(double [], double [], int);
void interpolacion(double[], double[], int);
void spline(double[], double[], int);
void coeficientes(double[], double[],double[], int);
double determinante(double [][max], int);
void adjunta(double[],double[], int, double [][max], double[], int);
void transponer(double[],double[], int, double [][max], double [][max], double[], int);
void mmult(double[],double[], int, double [][max], double [], int );
void derivNum(double [], double [], int );
void integNum(double [], double [], int );

int main(){
	int valid=2, n = max;
	double x[max], y[max];
	presentacion();
	subRutina(valid, x, y, n);
return 0;
}

//funciones del menu
void presentacion(void){
		printf("\n\n");
    	printf("\t\t\tUNIVERSIDAD NACIONAL AUT%cNOMA DE M%cXICO\n", 224, 144);
    	printf("\t\t\tFACULTAD DE ESTUDIOS SUPERIORES ACATL%cN\n", 181);
    	printf("\t\t\t  LIC EN MAT APLICADAS Y COMPUTACI%cN\n\n", 224);
    	printf("\t\t\t         M%cTODOS NUM%cRICOS II\n", 144, 144);
    	printf("\t\t\t    PROFA. CARRILLO RAM%cREZ TERESA\n\n", 214);
    	printf("\t\t\t   	    PAQUETE FINAL\n");
    	printf("\t\t\t         CASTILLO ORTIZ JORGE\n");
    	printf("\t\t\t     VEL%CZQUEZ BARRERA NO%C DAMI%CN\n\n", 181, 144,181);
    	printf("\t\t\t              GRUPO: 2452\n");
    	printf("\n\n");
    	system("pause");
}
void subRutina(int valid, double x[], double y[], int n){
	int optMen;
	//valid = 2 si se ingresara una nueva tabla

	do{	
		system("cls");
		printf("Escoja una opci%cn.\n\n", 162);
		printf("1.- Sistemas de ecuaciones no lineales.\n");
		printf("2.- Interpolaci%cn polinomial y ajuste de curvas.\n", 162);
		printf("3.- Diferenciaci%cn e integraci%cn num%crica.\n", 162, 162, 130);
		printf("4.- Salir.\n\n");
		scanf("%d", &optMen);
		if(optMen!=1&&optMen!=2&&optMen!=3&&optMen!=4)
			incorrecto();
	}while(optMen!=1&&optMen!=2&&optMen!=3&&optMen!=4);
	if(valid==2&&optMen!=4)
		system("cls");
	else if(valid!=2&&optMen!=1&&optMen!=4){
		printf("\n%cDesea usar la %cltima tabla introducida?\n1.- S%c.\n2.- No.\n", 168, 163, 161);
		scanf("%d", &valid);
	}
	switch(optMen){
			case 1:
				tipoMetodo(x, y, n, optMen, valid);
			break;
			case 2:
				if(valid==2)
					n=numPuntos();
				system("cls");
				leerTabla(x, y, n, optMen, valid);		
			break;
			case 3:
				system("cls");
				leerTabla(x, y, n, optMen, valid);
			break;	
			case 4:
				salir();
			break;
			default:
				incorrecto();
			break;	
		}
}
void backMenu(double x[], double y[], int n, int optMen, int valid){
	int opt, o;
	//interpolacion y diferenciacion
	if(optMen==2||optMen==3){
		do{
			printf("\n%cDesea cambiar la tabla o regresar al submen%c de ", 168, 163);
			if(optMen == 2)	
				printf("interpolaci%cn y ajuste de curvas?\n", 162);
			else if(optMen == 3)
			 	printf("diferenciaci%cn e integraci%cn num%crica?\n", 162, 162, 130);	
			printf("1.- Cambiar tabla.\n2.- Regresar al submen%c.\n3.- Salir.\n\n", 163);
			scanf("%d", &opt);
			if(opt!=1&&opt!=2&&opt!=3)
				incorrecto();
		}while(opt!=1&&opt!=2&&opt!=3);
		
		switch(opt){
			case 1:
				valid=2;
				subRutina(valid, x, y, n);
			break;
			case 2:
				tipoMetodo(x, y , n, optMen, valid);
			break;
			case 3:
				salir();
			break;
			default:
				incorrecto();
			break;	
		}
	}
	//newton
	else if(optMen==1){
		do{
		printf("1.- Regresar al submen%c de sistemas de ecuaciones no lineales.\n", 163);
		printf("2.- Regresar al men%c principal.\n", 163);
		printf("3.- Salir.\n\n");
	    scanf("%i",&o);
	    if(o!=1&&o!=2&&o!=3)
	    	incorrecto();
		}while(o!=1&&o!=2&&o!=3);
		switch(o){
	    	case 1:
	    		newton(x, y, n, valid);
	    	break;
	    	case 2:
	    		
	    		subRutina(valid, x, y, n);
	    	break;
	    	case 3:
	    		salir();
	    	break;
	    	default:
	    		incorrecto();
	    	break;
		}
	}
	else if(opt==4)
		salir();
}
void tipoMetodo(double x[], double y[], int n, int optMen, int valid){
	int opt, back, backMen;
	do{
		system("cls");
		back=0;
		backMen=0;
		switch(optMen){
			case 1:
				system("cls");
				newton(x ,y, n, valid);
			break;
			case 2:
				do{
					system("cls");
					printf("Seleccione m%ctodo.\n\n1.- Interpolaci%cn polinomial.\n2.- Ajuste de curvas.\n3.- Regresar al men%c principal.\n\n", 130, 162, 163);
					scanf("%d", &opt);
					switch(opt){
						case 1:
							interpolacion(x, y, n);
						break;
						case 2:
							spline(x, y, n);
						break;
						case 3:
							subRutina(1, x, y, n);
						break;
						default:
							incorrecto();
							back=1;
						break;
					}
				}while(back!=3);
			break;
			case 3:
				do{
					system("cls");
					printf("Seleccione m%ctodo.\n\n1.- Diferenciaci%cn numerica.\n2.- Integraci%cn num%crica.\n3.- Regresar al men%c principal.\n\n", 130, 162, 162, 130, 163);
					scanf("%d", &opt);
					switch(opt){
						case 1:
							derivNum(x, y, n);
						break;
						case 2:
							integNum(x, y, n);
						break;
						case 3:
							subRutina(1, x, y, n);
						break;
						default:
							incorrecto();
							back=1;
						break;
					}
				}while(back!=3);
			default:
				incorrecto();
				backMen=1;
			break;
		}	
	}while(backMen==1);
}
void salir(void){
	printf("\n\nAdi%cs.\n", 162);
	system("pause");
	exit(0);
}

//funciones de lectura
int numPuntos(void){
	int n;
		do{
		system("cls");
		printf("%cCu%cntos puntos desea insertar? ", 168, 160);
		scanf("%d", &n);
		if(n<=0){
			printf("\nLa cantidad debe ser mayor a 0, intente otra vez.\n");
			system("pause");
		}
	}while(n<=0);
return n;
}
void leerTabla(double x[], double y[], int n, int optMen, int valid){
	int i, k, auxv=0;
	double h, aux;
	if(valid==2){
		if(optMen == 2){
			for(i=0;i<n;i++){
				do{
					printf("Ingrese valor para x[%d]: ", i);
					scanf("%lf", &x[i]);
		    		if(i>0){
						for(k=0;k<i;k++){
							if(fabs(x[i]-x[k])<0.0000001){
								auxv=1;
								break;
							}
							else
								auxv=0;
						}
						if(auxv==1){
							printf("Valor repetido, inserte otra vez.\n\n");
						}
					}
				}while(auxv!=0);
				
				printf("Ingrese valor para y[%d]: ", i);
				scanf("%lf", &y[i]);
				printf("\n");
			}
			corregir(x, y, n, optMen, valid);
		}
		else if(optMen == 3){
			n=numPuntos();
			printf("Inserte tama%co de paso h: ", 164);
			scanf("%lf", &h);
			printf("\nInserte valor de x[0]: ");
			scanf("%lf", &x[0]);
			printf("Inserte valor de y[0]: ");
			scanf("%lf", &y[0]);
			for(i=1;i<n;i++){
				x[i]=x[i-1]+h;
				printf("\n\t\t x[%d]: %f\n", i, x[i]);
				printf("Inserte valor de y[%d]: ", i);
				scanf("%lf", &y[i]);
			}
			corregirSimp(x, y, n, optMen, valid);
		}
	}
	else{
		if(optMen == 3){
			aux = x[1]-x[0];
			for(int i=1;i<n;i++){
				if(aux==x[i]-x[i-1])
					aux=aux;
				else
					aux=0;
			}
			if(aux==0){
				printf("\nLos datos no estan igualmente espaciados, introduzca la tabla nuevamente.\n");
				system("pause");
				system("cls");
				valid=2;
				leerTabla(x, y, n, optMen, valid);
			}
		}
		corregirSimp(x, y, n, optMen, valid);
	}
}
void corregir(double x[], double y[], int n, int optMen, int valid){
	int i, opt[3], back, auxv=0, k;
	//se repite el menu hasta que sean correctos los datos
	do{
		back=0;
		system("cls");
		opt[0] = askDato(x, y, n);
		if(opt[0]!=1&&opt[0]!=2){
			incorrecto();
			back=1;
		}
		//si no son conrrectos los datos, se corregiran
		if(opt[0]==2){
			printf("\n%cQu%c conjunto desea corregir?\n1.- x[] \n2.- y[]\n3.- Regresar\n", 168, 130);
			scanf("%d", &opt[1]);
			switch(opt[1]){
				case 1:	//corregir x
					do{
						printf("\n%cQu%c %cndice desea corregir?: ", 168, 130, 161);
						scanf("%d", &opt[2]);
						//El indice debe ser mayor o igual a 0 y menor a n
						if(opt[2]<0||opt[2]>=n)
							incorrecto();
					}while(opt[2]<0||opt[2]>=n);
					do{
						printf("Ingrese valor para x[%d]: ", opt[2]);
						scanf("%lf", &x[opt[2]]);
			    		if(opt[2]>0){
							for(k=0;k<n;k++){
								if(fabs(x[opt[2]]-x[k])<0.0000001&&k!=opt[2]){
									auxv=1;
									break;
								}
								else
									auxv=0;
							}
							if(auxv==1){
								printf("Valor repetido, inserte otra vez.\n\n");
							}
						}
					}while(auxv!=0);
				break;
				case 2: //corregir y
					do{
						printf("\n%cQu%c %cndice desea corregir?: ", 168, 130, 161);
						scanf("%d", &opt[2]);
						if(opt[2]<0||opt[2]>=n)
							incorrecto();
					}while(opt[2]<0||opt[2]>=n);
					printf("\nInserte nuevo valor para y[%d]: ", opt[2]);
					scanf("%lf", &y[opt[2]]);
				break;
				case 3: //regresar
					back=1;
				break;
				default: //regresar al menu anterior en cualquier otro caso
					incorrecto();
					back=1;
				break;
			}
		}else if(opt[0]==1){
			tipoMetodo(x, y, n, optMen, valid);
		}
	}while(opt[0]==2||back==1);
}
void corregirSimp(double x[], double y[], int n, int optMen, int valid){
	int opt[2], back;
	do{
		back=0;
		system("cls");
		opt[0] = askDato(x, y, n);
		if(opt[0]!=1&&opt[0]!=2){
			incorrecto();
			back=1;
		}
		if(opt[0]==2){
			back=1;
			do{
				printf("\n%cQu%c %cndice  de y[] desea corregir?: ", 168, 130, 161);
				scanf("%d", &opt[1]);
				//El indice debe ser mayor o igual a 0 y menor a n
				if(opt[1]<0||opt[1]>=n)
					incorrecto();
			}while(opt[1]<0||opt[1]>=n);
			printf("\nInserte nuevo valor para y[%d]: ", opt[1]);
			scanf("%lf", &y[opt[1]]);
		}
		else if(opt[0]==1)
			tipoMetodo(x, y, n, optMen, valid);
	}while(opt[0]!=1||back==1);
}
int askDato(double x[], double y[], int n){
	int i, opt;
		//imprimir x, y
		for(i=0;i<n;i++)
			printf("x[%d] = %f\ty[%d] = %f\n", i, x[i], i, y[i]);
		do{
			printf("\n%cSon correctos?\n1.- S%c.\n2.- No.\n", 168, 161);
			scanf("%d", &opt);
			if(opt!=1&&opt!=2){
				incorrecto();
			}
		}while(opt!=1&&opt!=2);
	return opt;
}
void incorrecto(void){
	printf("Opci%cn incorrecta, vuelva a intentarlo.\n", 162);
	system("pause");
}

//funciones de sistemas de ecuaciones no lineales
void newton(double x[], double y[], int n, int valid){
    int op;
    menuNewt(&op, x, y, n, valid);
}
void menuNewt (int *op, double x[], double y[], int n, int vf){  
bool valid=true;
    do{
    	system("cls");
  		printf("1. f(x,y)=x^2+xy-10=0\n   g(x,y)=y+3xy^2-50=0\n");
  		printf("\n2. f(x,y)=x^2+y^2-9=0\n   g(x,y)=-e^x-2y-3=0\n");
  		printf("\n3. f(x,y,z)=2x^2-4x+y^2+3z^2+6z+2= 0\n   g(x,y,z)=x^2+y^2-2y+2z^2-5=0\n   h(x,y,z)=3x^2-12x+y^2-3z^2+8=0\n");
  		printf("\n4. f(x,y,z)=x^2-4x+y^2=0\n   g(x,y,z)=x^2-x-12y+1=0\n   h(x,y,z)=3x^2-12x+y^2-3z^2+8=0\n");
  		printf("\n5. Regresar al men%c principal.\n", 163);
  		printf("\n\nElija el sistema de ecuaciones");
  		if(!valid)
  			printf("\nDebe elegir una opci%cn valida: ", 162);
  		else
  			printf(": ");
		scanf("%d", op);
		if(*op<1 || *op>5)
			valid=false;
    }while(*op<1 || *op>5);
    
    switch(*op){
    	case 1:
    		primerSistema();
    		backMenu(x, y, n, 1, vf);
   		break;
    	case 2:
    		segundoSistema();
    		backMenu(x, y, n, 1, vf);

    	break;
    	case 3:
    		tercerSistema();
    		backMenu(x, y, n, 1, vf);
    	break;
    	case 4:
    		cuartoSistema();
    		backMenu(x, y, n, 1, vf);
    	break;
    	case 5:
    		subRutina(1, x, y, n);
    	break;
  		default:
			incorrecto();
  		break;
	}
}
void primerSistema(void){ 
    int i, k, cont=0, maxx;
    float xy[2],fx[2],error=1,xym1[2],errores[2],tol;
    float j[2][2];
    system("cls");
    printf("f(x,y)=x^2+xy-10=0\ng(x,y)=y+3xy^2-50=0\n");
    printf("\nIntroduzca el vector inicial:\nx: ");
    scanf("%f",&xy[0]);
    printf("y: ");
    scanf("%f",&xy[1]);
    printf("Introduzca tolerancia: ");
    scanf("%f", &tol);
    tol=fabs(tol);
    do{
	    printf("Introduzca maximo de iteraciones: ");
	    scanf("%d", &maxx);
	    if(maxx<=0)
	    	printf("Escoja un numero mayor a 0.\n");
	}while(maxx<=0);
    
    //validar que el denomindar no sea 0
    if((12*xy[0]*xy[0]*xy[1]+xy[0]*(3*xy[1]*xy[1]+2)+xy[1])!=0){
    printf("\nX\t\tF(X)\t\t     J^(-1)(X)\t\tNorma\n");
	    while(error>tol){
	        //evaluacion en funciones
	        fx[0]=(xy[0]*xy[0])+(xy[0]*xy[1])-10;
	        fx[1]=xy[1]+(3*xy[0]*(xy[1]*xy[1]))-50;
	        
	        //Formulas matriz jacobiana inversa
	        j[0][0]=(6*xy[0]*xy[1]+1)/(12*xy[0]*xy[0]*xy[1]+xy[0]*(3*xy[1]*xy[1]+2)+xy[1]);
	        j[0][1]=((-1)*xy[0])/(12*xy[0]*xy[0]*xy[1]+xy[0]*(3*xy[1]*xy[1]+2)+xy[1]);
	        j[1][0]=((-3)*xy[1]*xy[1])/(12*xy[0]*xy[0]*xy[1]+xy[0]*(3*xy[1]*xy[1]+2)+xy[1]);
	        j[1][1]=(2*xy[0]+xy[1])/(12*xy[0]*xy[0]*xy[1]+xy[0]*(3*xy[1]*xy[1]+2)+xy[1]);
	       
	        //guardamos x,y
	        xym1[0]=xy[0];
	        xym1[1]=xy[1];
	        
	        //xalculamos nuevos x,y
	        xy[0]-=(fx[0]*j[0][0])+(fx[1]*j[0][1]);
	        xy[1]-=(fx[0]*j[1][0])+(fx[1]*j[1][1]);
	        /*for(i=0;i<2;i++)
	        {
	            printf("\n\nnuevos x,y %f  ",xy[i]);
	        }*/
	        //calculo del error
	        errores[0]=fx[0];
	        if(errores[0]<0)
				errores[0]=errores[0]*(-1);
	        errores[1]=fx[1];
	        if(errores[1]<0)
				errores[1]=errores[1]*(-1);
	        if(errores[0]>errores[1])
	        {
	            error=errores[0];
	        }else error=errores[1];
	        
	        printf("\n\n%f\t%f\t%f  %f\t%f",xym1[0],fx[0],j[0][0],j[0][1],error);
	        printf("\n%f\t%f\t%f  %f",      xym1[1],fx[1],j[1][0],j[1][1]);
	        
	        //contar numeo de iteraciones;
	        cont++;
	      	if(cont==maxx)
	      		break;
	    } 
    	printf("\n\nRaiz aproximada: ( %f, %f )",xy[0],xy[1]);
    	printf("\nNumero de iteraciones: %d", cont);
   	}
   	else
        printf("\n\nNo es posible obtener la matriz inversa!");
    printf("\n\n");
}
void segundoSistema(void){ 
    int cont=0,maxx;
    float xy[2],fx[2],error=1,xym1[2],errores[2],tol;
    float j[2][2];
    system("cls");
    printf("f(x,y)=x^2+y^2-9=0\ng(x,y)=-e^x-2y-3=0\n");
    printf("\nIntroduzca el vector inicial:\nx: ");
    scanf("%f",&xy[0]);
    printf("y: ");
    scanf("%f",&xy[1]);
   
    printf("Introduzca tolerancia: ");
    scanf("%f", &tol);
    tol=fabs(tol);
    do{
	    printf("Introduzca maximo de iteraciones: ");
	    scanf("%d", &maxx);
	    if(maxx<=0)
	    	printf("Escoja un numero mayor a 0.\n");
	}while(maxx<=0);
    
    //validar que el denomindar no sea 0
    if((exp(xy[0])*xy[1]-2*xy[0])!=0){
    	printf("\nX\t\tF(X)\t\t     J^(-1)(X)\t\tNorma\n");
	    while(error>tol){
	        //evaluacion en funciones
	        fx[0]=xy[0]*xy[0]+xy[1]*xy[1]-9;
	        fx[1]=(-1)*exp(xy[0])-2*xy[1]-3;
	        
	        //Formulas matriz jacobiana inversa
	        j[0][0]=(-1)/((exp(xy[0]))*xy[1]-2*xy[0]);
	        j[0][1]=((-1)*xy[1])/((exp(xy[0]))*xy[1]-2*xy[0]);
	        j[1][0]=(exp(xy[0])/2)/((exp(xy[0]))*xy[1]-2*xy[0]);
	        j[1][1]=xy[0]/((exp(xy[0]))*xy[1]-2*xy[0]);
	       
	        //guardamos x,y
	        xym1[0]=xy[0];
	        xym1[1]=xy[1];
	        
	        //xalculamos nuevos x,y
	        xy[0]-=(fx[0]*j[0][0])+(fx[1]*j[0][1]);
	        xy[1]-=(fx[0]*j[1][0])+(fx[1]*j[1][1]);
	        /*for(i=0;i<2;i++)
	        {
	            printf("\n\nnuevos x,y %f  ",xy[i]);
	        }*/
	        //calculo del error
	        errores[0]=fx[0];
	        if(errores[0]<0)
				errores[0]=errores[0]*(-1);
				
	        errores[1]=fx[1];
	        if(errores[1]<0)
				errores[1]=errores[1]*(-1);
				
				
	        if(errores[0]>errores[1])
	        {
	            error=errores[0];
	        }else error=errores[1];
	        
	        printf("\n\n%f\t%f\t%f  %f\t%f",xym1[0],fx[0],j[0][0],j[0][1],error);
	        printf("\n%f\t%f\t%f  %f",      xym1[1],fx[1],j[1][0],j[1][1]);
	        
	        //contar numeo de iteraciones;
	        cont++;
	        if(cont==maxx)
	      		break;
    	} 
    	printf("\n\nRaiz aproximada: ( %f, %f )",xy[0],xy[1]);
    	printf("\nNumero de iteraciones: %d", cont);	  
	}
	else
        printf("\n\nNo es posible obtener la matriz inversa!");  
    printf("\n\n");
}
void tercerSistema(void){
	int cont=0, maxx;
    float xy[3],fx[3],error=1,xym1[3],errores[3],tol;
    float j[3][3];
    system("cls");
    printf("f(x,y)=2x^2-4x+y^2+3z^2+6z+2=0\ng(x,y)=x^2+y^2-2y+2z^2-5=0\nh(x,y,z)=3x^2-12x+y^2-3z^2+8=0\n");
    printf("\nIntroduzca el vector inicial:\nx: ");
    scanf("%f",&xy[0]);
    printf("y: ");
    scanf("%f",&xy[1]);
    printf("z: ");
	scanf("%f", &xy[2]);
	
    printf("Introduzca tolerancia: ");
    scanf("%f", &tol);
    tol=fabs(tol);
    do{
	    printf("Introduzca maximo de iteraciones: ");
	    scanf("%d", &maxx);
	    if(maxx<=0)
	    	printf("Escoja un numero mayor a 0.\n");
	}while(maxx<=0);
	    //validar que el denomindar no sea 0
	if((2* xy[0]* (7 *xy[1] *xy[2] + 6 *xy[1] - 15 *xy[2] - 9) - 4* xy[1]* (8* xy[2] + 9) + 48* xy[2] + 36)!=0){	
    	printf("\nX\t\tF(X)\t\t\tJ^(-1)(X)\t\t\tNorma\n");
	    while(error>tol){
	        //evaluacion en funciones
	        fx[0]=2*xy[0]*xy[0]-4*xy[0]+xy[1]*xy[1]+3*xy[2]*xy[2]+6*xy[2]+2;
	        fx[1]=xy[0]*xy[0]+xy[1]*xy[1]-2*xy[1]+2*xy[2]*xy[2]-5;
	        fx[2]=3*xy[0]*xy[0]-12*xy[0]+xy[1]*xy[1]-3*xy[2]*xy[2]+8;
	        
	        //Formulas matriz jacobiana inversa
	    	j[0][0]=(5 *xy[1]* xy[2] - 3 *xy[2]) /(2* xy[0]* (7 *xy[1] *xy[2] + 6 *xy[1] - 15 *xy[2] - 9) - 4* xy[1]* (8* xy[2] + 9) + 48* xy[2] + 36);
			j[0][1]=(-3 *(2 *xy[2] *xy[1] + xy[1]) )/(2* xy[0]* (7 *xy[1] *xy[2] + 6 *xy[1] - 15 *xy[2] - 9) - 4* xy[1]* (8* xy[2] + 9) + 48* xy[2] + 36);
			j[0][2]=(xy[2]* xy[1] + 3* xy[1] - 3* xy[2] - 3)/(2* xy[0]* (7 *xy[1] *xy[2] + 6 *xy[1] - 15 *xy[2] - 9) - 4* xy[1]* (8* xy[2] + 9) + 48* xy[2] + 36);
	
			j[1][0]=(3 *(4* xy[2] - 3 *xy[0] *xy[2]))/(2* xy[0]* (7 *xy[1] *xy[2] + 6 *xy[1] - 15 *xy[2] - 9) - 4* xy[1]* (8* xy[2] + 9) + 48* xy[2] + 36);
			j[1][1]=( -3 *(-5 *xy[2] *xy[0] - 3 *xy[0] + 8* xy[2] + 6) )/(2* xy[0]* (7 *xy[1] *xy[2] + 6 *xy[1] - 15 *xy[2] - 9) - 4* xy[1]* (8* xy[2] + 9) + 48* xy[2] + 36);
			j[1][2]=( xy[2]* xy[0] - 3* xy[0] - 4* xy[2])/(2* xy[0]* (7 *xy[1] *xy[2] + 6 *xy[1] - 15 *xy[2] - 9) - 4* xy[1]* (8* xy[2] + 9) + 48* xy[2] + 36);
	 
			j[2][0]=(2* xy[1]* xy[0] - 3 *xy[0] - 6* xy[1] + 6)/(2* xy[0]* (7 *xy[1] *xy[2] + 6 *xy[1] - 15 *xy[2] - 9) - 4* xy[1]* (8* xy[2] + 9) + 48* xy[2] + 36);
			j[2][1]=(4 *xy[1] - xy[0]* xy[1])/(2* xy[0]* (7 *xy[1] *xy[2] + 6 *xy[1] - 15 *xy[2] - 9) - 4* xy[1]* (8* xy[2] + 9) + 48* xy[2] + 36);
			j[2][2]=(-xy[1]* xy[0] + 2* xy[0] + 2* xy[1] - 2)/(2* xy[0]* (7 *xy[1] *xy[2] + 6 *xy[1] - 15 *xy[2] - 9) - 4* xy[1]* (8* xy[2] + 9) + 48* xy[2] + 36);
	       
	        //guardamos x,y
	        xym1[0]=xy[0];
	        xym1[1]=xy[1];
	        xym1[2]=xy[2];
	        
	        //xalculamos nuevos x,y
	        xy[0]-=(fx[0]*j[0][0])+(fx[1]*j[0][1])+fx[2]*j[0][2];
	        xy[1]-=(fx[0]*j[1][0])+(fx[1]*j[1][1])+fx[2]*j[1][2];
	        xy[2]-=(fx[0]*j[2][0])+(fx[1]*j[2][1])+fx[2]*j[2][2];
	    
	        //calculo del error	        
	        //obteniendo valor absoluto

	        errores[0]=fx[0];
	        if(errores[0]<0)
				errores[0]=errores[0]*(-1);
				
	        errores[1]=fx[1];
	        if(errores[1]<0)
				errores[1]=errores[1]*(-1);
				
			errores[2]=fx[2];
			if(errores[2]<0)
				errores[2]=errores[2]*(-1);
				
				
	        if(errores[0]>errores[1]&&errores[0]>errores[2])
	            error=errores[0];
	        else if(errores[1]>errores[2]&&errores[1]>errores[0])
	        	error=errores[1];
	        else if(errores[2]>errores[1]&&errores[2]>errores[0])
	        	error=errores[2];
	    
	        printf("\n\n%f\t%f\t%f  %f  %f\t%f",xym1[0],fx[0],j[0][0],j[0][1],j[0][2],error);
	        printf(  "\n%f\t%f\t%f  %f  %f",    xym1[1],fx[1],j[1][0],j[1][1],j[1][2]);
	        printf(  "\n%f\t%f\t%f  %f  %f",    xym1[2],fx[2],j[2][0],j[2][1],j[2][2]);
	        
	        //contar numeo de iteraciones;
	        cont++;
	        if(cont==maxx)
	      		break;
	    } 
    	printf("\n\nRaiz aproximada: ( %f, %f , %f)",xym1[0],xym1[1], xym1[2]);
    	printf("\nNumero de iteraciones: %d", cont);
    }
    else
        printf("\n\nNo es posible obtener la matriz inversa!");
    printf("\n\n");
}
void cuartoSistema(void){
	int cont=0, maxx;
    float xy[3],fx[3],error=1,xym1[3],errores[3],tol;
    float j[3][3];
    system("cls");
    printf("f(x,y,z)=x^2-4x+y^2=0\ng(x,y,z)=x^2-x-12y+1=0\nh(x,y,z)=3x^2-12x+y^2-3z^2+8=0\n");
    printf("\nIntroduzca el vector inicial:\nx: ");
    scanf("%f",&xy[0]);
    printf("y: ");
    scanf("%f",&xy[1]);
    printf("z: ");
	scanf("%f", &xy[2]);

    printf("Introduzca tolerancia: ");
    scanf("%f", &tol);
    tol=fabs(tol);
    do{
	    printf("Introduzca maximo de iteraciones: ");
	    scanf("%d", &maxx);
	    if(maxx<=0)
	    	printf("Escoja un numero mayor a 0.\n");
	}while(maxx<=0);
	
	    //validar que el denomindar no sea 0
	if((2* xy[1] *xy[0] + 12* xy[0] - xy[1] - 24)==0||(12* xy[0]* xy[2] + 2* xy[0] *xy[1] *xy[2] - xy[1] *xy[2] - 24 *xy[2])==0||xy[2]!=0){
        printf("\nX\t\tF(X)\t\t\tJ^(-1)(X)\t\t\tNorma\n");
	    while(error>tol){
	        //evaluacion en funciones
	        fx[0]=xy[0]*xy[0]-4*xy[0]+xy[1]*xy[1];   
			fx[1]=xy[0]*xy[0]-xy[0]-12*xy[1]+1;   
			fx[2]=3*xy[0]*xy[0]-12*xy[0]+xy[1]*xy[1]-3*xy[2]*xy[2]+8;
	        
	        //Formulas matriz jacobiana inversa
	    	j[0][0]= (36/(2* xy[1] *xy[0] + 12* xy[0] - xy[1] - 24) )/6;
			j[0][1]= ((6 *xy[1])/(2* xy[1] *xy[0] + 12* xy[0] - xy[1] - 24))/6;
			j[0][2]= (0)/6;
	  
	  
			j[1][0]= (-(6 *(1 - 2* xy[0]))/(4 *xy[1] *xy[0] + 24* xy[0] - 2 *xy[1] - 48) )/6;
			j[1][1]= (-(6 *(xy[0] - 2))/(2* xy[1] *xy[0] + 12* xy[0] - xy[1] - 24)) /6;
			j[1][2]=  (0)/6;
	  
	  
			j[2][0]= ((2 *xy[1]* xy[0] + 36* xy[0] - xy[1] - 72)/(12* xy[0] *xy[2] + 2* xy[0] *xy[1] *xy[2] - xy[1]* xy[2] - 24 *xy[2])) /6;
			j[2][1]= ((4* (xy[0] *xy[1] - 2* xy[1]))/(12* xy[0]* xy[2] + 2* xy[0] *xy[1] *xy[2] - xy[1] *xy[2] - 24 *xy[2]) )/6;
			j[2][2]= ((-1/xy[2]))/6;
	    
	        //guardamos x,y
	        xym1[0]=xy[0];
	        xym1[1]=xy[1];
	        xym1[2]=xy[2];
	        
	        //xalculamos nuevos x,y
	        xy[0]-=(fx[0]*j[0][0])+(fx[1]*j[0][1])+fx[2]*j[0][2];
	        xy[1]-=(fx[0]*j[1][0])+(fx[1]*j[1][1])+fx[2]*j[1][2];
	        xy[2]-=(fx[0]*j[2][0])+(fx[1]*j[2][1])+fx[2]*j[2][2];
	    
	        //calculo del error
	        
	        //obteniendo valor absoluto
	        errores[0]=fx[0];
	        if(errores[0]<0)
				errores[0]=errores[0]*(-1);
				
	        errores[1]=fx[1];
	        if(errores[1]<0)
				errores[1]=errores[1]*(-1);
				
			errores[2]=fx[2];
			if(errores[2]<0)
				errores[2]=errores[2]*(-1);
				
				
	        if(errores[0]>errores[1]&&errores[0]>errores[2])
	            error=errores[0];
	        else if(errores[1]>errores[2]&&errores[1]>errores[0])
	        	error=errores[1];
	        else if(errores[2]>errores[1]&&errores[2]>errores[0])
	        	error=errores[2];
	    
	        printf("\n\n%f\t%f\t%f  %f  %f\t\t%f",xym1[0],fx[0],j[0][0],j[0][1],j[0][2],error);
	        printf(  "\n%f\t%f\t%f  %f  %f",    xym1[1],fx[1],j[1][0],j[1][1],j[1][2]);
	        printf(  "\n%f\t%f\t%f  %f  %f",    xym1[2],fx[2],j[2][0],j[2][1],j[2][2]);
	        
	        //contar numeo de iteraciones;
	        cont++;
	        if(cont==maxx)
	      		break;
	    } 		
    	printf("\n\nRaiz aproximada: ( %f, %f , %f)",xym1[0],xym1[1], xym1[2]);
    	printf("\nNumero de iteraciones: %d", cont);
	}
	else
        printf("\n\nNo es posible obtener la matriz inversa!");
    printf("\n\n");
}

//funciones de interpolacion y ajuste de curvas
bool ordenar(double x[], double y[], int n){
	int i, j, temp, index;
	bool verif;
	double x_aux[n], y_aux[n];
	
	for(i=1;i<n;i++){
		//si no estan ordenados = false
		if(x[i]<x[i-1]){
			verif = false;
			break;
		}else{
			verif=true;
		}
	}
	if(!verif){
		for(i=0;i<n;i++){
			x_aux[i]=x[i];
			y_aux[i]=y[i];
		}
		
		//metodo burbuja para x
		for(i = 0; i < (n- 1); i++){ 
			for (j = i + 1; j < n; j++){ 
			  if (x[j] < x[i]){ 
			    temp = x[j]; 
			    x[j] = x[i]; 
			    x[i] = temp; 
			  } 
			} 
		} 
		
		//reasignar posiciones de y
		for(i=0;i<n;i++){
			if(x_aux[i]!=x[i]){
				temp=x[i];
				//buscar posicion original de x
				for(j=0;j<n;j++){
					if(temp==x_aux[j]){
						index=j;
					}
				}
				y[i]=y_aux[index];
			}	
		}
	}
	return verif;
}
void interpolacion(double x[], double y[], int n){
	int i , m=n, j, grad, opt;
	double xInterp;
	double a[n][n];
	
	//verificar S estan ordenados
	do{
		system("cls");
		if(ordenar(x, y, n))
			printf("Los datos est%cn ordenados.\n", 160);
		else
			printf("Los datos se ordenaron.\n");
		printf("Inserte valor de x a interpolar: ");
		scanf("%lf", &xInterp);
		//validar que x este en el intervalo
		if(xInterp<x[0]||xInterp>x[n-1]){
			printf("El valor no se encuentra en el intervalo (%.2f, %.2f), vuelva a intentarlo.\n", x[0], x[n-1]);
			system("pause");
		}else{
			//validar el grado del polinomio 
			do{
				printf("\nInserte grado del polinomio: ");
				scanf("%d", &grad);
				if(grad>=n||grad<0){
					printf("\nPuntos insuficientes para construir el polinomio de grado %d. Inserte un grado entre 0 y %d.\n", grad, n-1);
					system("pause");
				}
				else if(grad<0){
					printf("Inserte un grado mayor o igual a 0.");
					system("pause");
				}
			}while(grad>=n||grad<0);
			
			//declarar polinomio del grado obtenido
			 double multx[grad+1], fx[grad+1], pix[grad+1];
			//asignar diferencias divididas
			for(j=0;j<n;j++){
				for(i=0;i<m;i++){
					if(j==0){	
						a[i][j] = y[i];
					}else{
						a[i][j] = (a[i+1][j-1]-a[i][j-1])/(x[i+j]-x[i]);
					}
				}
				m--;
			}
			//impresion de tabla
			m=n;
			printf("\nx[i]\t\t");
			for(j=0;j<n;j++)
				printf("f^[%d]\t\t", j);
			printf("\n");
			for(j=0;j<n;j++){
				printf("%f\t", x[j]);
				for(i=0;i<m;i++){
					printf("%f\t", a[j][i]);
				}
			printf("\n");
			m--;
			}
			//llenar multiplicadores (x-xi)*...*(x-xn)
			for(i=0;i<=grad;i++){
				if(i==0)
					multx[i]=1;
				else{
					multx[i]=multx[i-1]*(xInterp-x[i-1]);
				}
			}
			//multilicar f^[i] * (x-xi)* ... *(x-xn)
			for(i=0;i<=grad;i++){
				fx[i]=a[0][i]*multx[i];
			}	
			printf("\n");
			//sumar los grados
			for(i=0;i<=grad;i++){
				if(i==0)
					pix[i]=fx[i];
				else
					pix[i]=pix[i-1]+fx[i];
			}
			printf("\nEl valor de f(x) interpolado en x = %f  de grado %d es: %f.\n\n", xInterp, grad, pix[grad]);
			do{	
				printf("%cDesea interpolar otro punto de la misma tabla?\n1.- S%c.\n2.- No.\n", 168, 161);
				scanf("%d", &opt);
				if(opt!=1&&opt!=2){
					incorrecto();
				}
			}while(opt!=1&&opt!=2);
		}
	}while(xInterp<x[0]||xInterp>x[n-1]||opt==1);
	backMenu(x,y,n,2,1);
}
void spline(double x[], double y[], int n){
	int i, j, d;
	double h[n-1];
	double f1[n-1];
	double matrixA [max][max];
	double matrixB [n-2];
	double S[n];
	if(n==1){
		printf("\nN%cmero de puntos insuficientes.\n", 163);
		backMenu(x, y, n, 2, 1);
	}
	else if(n==2){
		S[0]=0, S[1]=0;
		coeficientes(x, y, S, n);
	}
	else{
		for(i=0; i<n-1; i++){
			h[i] = x[i+1]-x[i];
			f1[i] = (y[i+1]-y[i])/(h[i]);
		}
		
		//Asignacion de la matriz A, construida con las diferencias h
		for(j=0; j<n-2; j++){
			if(j==0)
				for(i=0;i<n-2;i++)
					if(i==0)
						matrixA[j][i] = 2*(h[j+1]+h[j]);
					else if(i==1)
						matrixA[j][i] = h[j+1];
					else
						matrixA[j][i] = 0;
			else if(j>0&&j<n-2)
				for(i=0;i<n-2;i++)
					if (i-j == -1)
						matrixA[j][i] = h[j];
					else if (i-j == 0)
						matrixA[j][i] = 2*(h[j]+h[j+1]);
					else if (i-j ==1)
						matrixA[j][i] = h[j+1];
					else
						matrixA[j][i] = 0;
			else
				for(i=0;i<n-2;j++)
					if(i-j == -1)
						matrixA[j][i] = h[j];
					else if(i-j == 0)
						matrixA[j][i] = 2*(h[j]+h[j+1]);
					else
						matrixA[j][i] = 0;
		}
		
		//Asignacion de la matriz B construida con las difernecias f1
		for(i=0;i<n-2;i++)
			matrixB[i] = 6*(f1[i+1]-f1[i]);

		/*
		//Imprimir para comprobar
		printf("\nDiferencias x\n");
		for(i=0;i<n-1;i++)
			printf("%f\t", h[i]);
		printf("\nDiferencias y\n");
		for(i=0;i<n-1;i++)	
			printf("%f\t", f1[i]);
		printf("\nMatriz A\n");
		for(i=0;i<n-2;i++){
			for(j=0;j<n-2;j++)
				printf("%f\t", matrixA[i][j]);
			printf("\n");
		}
		printf("\nMatriz B\n");
		for(i=0;i<n-2;i++)	
			printf("%f\t", matrixB[i]);
		*/
		
		//Inversa de matriz 1x1
		if(n==3){
			S[0] = 0, S[1] = matrixB[0] / matrixA[0][0], S[2]=0;
			coeficientes(x, y, S, n);
		}
		else{
			//Pura validacion, no se si realmente pueda ocurrir que el det sea 0 con este metodo	
			d = determinante(matrixA, n-2);
		  	if (d == 0){
		   		printf("\nLa matriz de diferencias x no tiene inversa.\n");
		   		backMenu(x, y, n, 2, 1);
		   	}
		  	else
		   		adjunta(x, y, n, matrixA, matrixB,n-2);
	   	}
	}
}
void coeficientes(double x[], double y[], double S[], int n){
	int i;
	double h[n], f1[n], a[n-1], b[n-1], c[n-1], d[n-1];
	for(i=0;i<n-1;i++){
		h[i]=x[i+1]-x[i];
		f1[i]=(y[i+1]-y[i])/h[i];
	}
	//Se asignan los coeficientes de las x
	for(i=0;i<n-1;i++){
		a[i]=(S[i+1]-S[i])/(6*h[i]);
		b[i]=S[i]/2;
		c[i]=f1[i]-((S[i+1]+2*S[i])/6)*h[i];
		d[i]=y[i];
	}
	//Imrpimir funcion a trozos
	printf("\nAjuste de curvas por spline c%cbico.\n", 163);
	for(i=0;i<n-1;i++){
		if(i<n-2)
			if(x[i]<x[i+1])
				printf("%.2f <= x < %.2f, \t", x[i], x[i+1]);
			else
				printf("%.2f > x >= %.2f, \t", x[i], x[i+1]);
		else
			if(x[i]<x[i+1])
				printf("%.2f <= x <= %.2f, \t", x[i], x[i+1]);
			else
				printf("%.2f >= x >= %.2f, \t", x[i], x[i+1]);
		printf("f(x) = %f (x-%.2f)^3 +\t%f (x-%.2f)^2 +\t%f (x-%.2f) +\t%.2f\n", a[i], x[i], b[i], x[i], c[i], x[i], d[i]);
	}
	backMenu(x, y, n, 2, 1);
}
double determinante(double a[max][max], int k){
	double s = 1, det = 0, aux[max][max];
	int i, j, m, n, c;
	
	//Si el tamanio es uno, devuelve el elemento
	if (k == 1){
		return (a[0][0]);
	}else{
		det = 0;
	
	//recorre los cofactores
	for (c = 0; c < k; c++){
		m = 0;
		n = 0;
		
		//recorre elementos de la matriz 
		for (i = 0;i < k; i++){
			for (j = 0 ;j < k; j++){
				aux[i][j] = 0;
				if (i != 0 && j != c)	{
					//guarda los elementos en una nueva matriz
					aux[m][n] = a[i][j];
					if (n < (k - 2))
						n++;
					else{
						n = 0;
						m++;
					}
				}
			}
		}
		//funcion recursiva para recorrer elementos de la submatriz
		det = det + s * (a[0][c] * determinante(aux, k - 1));
		//alternar signo del cofactor
		s = -1 * s;
		}
	}
	return (det);
}
void adjunta(double x[], double y[], int npts, double matrixA[max][max], double matrixB[], int size){
	double aux[max][max], cofactor[max][max];
	int p, q, m, n, i, j;
	//Se usan 4 for anidados por que es la matriz madre y la que esta entro de ella, con sus respectivos i,j
	for (q = 0;q < size; q++){
		for (p = 0;p < size; p++){
			//m y n son posiciones que volveran a su lugar tras recorrres el cofactor
			m = 0;
			n = 0;
			for (i = 0;i < size; i++){
				for (j = 0;j < size; j++){
					//Eliminar fila q y columna p
					if (i != q && j != p){
						aux[m][n] = matrixA[i][j];
						if (n < (size - 2))
							n++;
						else{
							n = 0;
							m++;
						}
					}
				}
			}
			// (-1)^(i+j)*Adj(A*)
			cofactor[q][p] = pow(-1, q + p) * determinante(aux, size - 1);
		}
	}
	transponer(x, y, npts, matrixA, cofactor, matrixB, size);
}
void transponer(double x[], double y[], int npts, double matrixA[max][max], double cofactor[max][max], double matrixB[], int n){
//Pase muchos parametros para ir reciclando los vectores originales, me dio hueva usar punteros
int i, j;
double aux[max][max], inversa[max][max], d;
	//Guardar los elementos de la matriz e cofactores en una matriz auxiliar
	for (i = 0;i < n; i++){
		for (j = 0;j < n; j++)
			aux[i][j] = cofactor[j][i];
	}
	d = determinante(matrixA, n);
	
	//Calcula los elementos de la inversa dividiendo la ajunta entre el determinante
	for (i = 0;i < n; i++){
		for (j = 0;j < n; j++){
		inversa[i][j] = aux[i][j] / d;
		}
	}
	
	mmult(x, y, npts, inversa, matrixB, n);
}
void mmult(double x[], double y[], int npts, double matA[][max], double matB[], int n){
	int i, j;
	double matS[npts];
	
	//Definir spline normal con 0s en los extremos
	matS[0]=0;
	for(i=0;i<n;i++){
		matS[i+1]=0;
		for(j=0;j<n;j++){
			//Los valores de en medio se obtienen multiplicando A^(-1) X B
			matS[i+1]+=matA[i][j]*matB[j];
		}
	}
	matS[n+2]=0;
		
	coeficientes(x, y, matS, npts);
}

//funciones de diferenciacion e integracion numeica
void derivNum(double x[], double y[], int n){
	int i, posInterv[2]={-1, -1}, aux=-1;
	double h, df1[n-1], df2[n-2], dy[n],interv[2];
	h=x[1]-x[0];
	
	for(i=0;i<n-1;i++)
		df1[i]=y[i+1]-y[i];
	for(i=0;i<n-2;i++)
		df2[i]=df1[i+1]-df1[i];
	for(i=0;i<n;i++){
		if(i==0||i==n-1)
			//comodin ;)
			dy[i]=0;
		else
			dy[i]=(y[i+1]-y[i-1])/(2*h);
	}
	do{
		do{
			system("cls");
			printf("Inserte intervalo de valores para los que se desean conocer las derivadas.\n\n");
			printf("x_{0} = ");
			scanf("%lf", &interv[0]);
			printf("x_{1} = ");
			scanf("%lf", &interv[1]);
			if(interv[0]>interv[1]){
				printf("\nx_{1} debe ser mayor que x_{0}. Intente otra vez.\n");
				system("pause");
			}
		}while(interv[0]>interv[1]);
		//Buscar valores de x
		
		for(i=0;i<n;i++){
			if(fabs(interv[0]-x[i])<0.000001)
				posInterv[0]=i;
			if(fabs(interv[1]-x[i])<0.000001)
				posInterv[1]=i;	
		}

		for(i=0;i<2;i++)
			if(posInterv[i]==-1)
				printf("\nx = %f no se encuentra en la tabla, intente de nuevo.",  interv[i]);
			
			
		printf("\n");
		if(posInterv[0]==-1||posInterv[1]==-1)
			system("pause");
	}while(posInterv[0]==-1||posInterv[1]==-1);
	
	printf("\nDiferenciaci%cn por diferencias centradas.\n", 162);
	for(i=posInterv[0];i<=posInterv[1];i++)
		if(i==0||i==n-1)
			printf("x = %f\tf(x) = %f\t   f'(x) = Desconocido\n", x[i], y[i]);
		else
			printf("x = %f\tf(x) = %f\t   f'(x) = %f\n", x[i], y[i], dy[i]);
			
	backMenu(x, y, n, 3, 1);
}
void integNum(double x[], double y[], int n){
	int i, j,coefS3[n], corte=3, metod;
	double inty[n], I=0, h, aux=0;
	h=x[1]-x[0];
	//coeficientes de simpson 1/3;
	//1,4,2,4,2,...,4,1
	coefS3[0]=1;
	if(n==1)
		metod=0;
	else if(n==2){
		coefS3[1]=1;
		I=(y[0]+y[1])*h*0.5;
		metod=1;
	}
	else if(n>2){
		for(i=1;i<=n;i+=2){
			if(i+3<n||i+2==n){
				coefS3[i]=4;
				if(i+5<n||i+4==n)
					coefS3[i+1]=2;
				else
					coefS3[i+1]=1;
					//valor en el que se reiniciara la suma
					corte=i+1;
			}
			//combinar con simpson 1/8 si los intervalos n son pares
			//1,3,3,2,3,3,2,...,3,3,1
			else {
				coefS3[i]=3;
				coefS3[i+1]=3;
				coefS3[i+2]=1;
				break;
			}
		}
	
		//multiplicar coeficientes por f(x)
		for(i=0;i<n;i++)
			inty[i]=y[i]*coefS3[i];
		
		//sumar valores y multiplicar por h
		
		for(i=0;i<=corte;i++){
			metod=2;
			I+=inty[i];
		}
		if(I!=4)
			I*=(h*(1.0/3.0));
		else if(I==4)
			I*=(h*(3.0/8.0));
		if(corte!=n-1){
			metod=3;
			for(i=corte;i<n;i++)
				aux+=inty[i];
			aux*=(h*(3.0/8.0));
		}
		I+=aux;
	}
	if(metod==1)
		printf("\nIntegraci%cn por regla del trapecio ", 162);
	else if(n==4)
		printf("\nIntegraci%cn por regla de Simpson 3/8 ", 162);	
	else if(metod==2)
		printf("\nIntegraci%cn por regla de Simpson 1/3 ", 162);
	else if(metod==3)
		printf("\nIntegraci%cn por regla de Simpson 1/3 + 3/8 ", 162);
	
	if(metod==0){
		printf("\nIntegral definida en [%f, %f]", x[0], x[0]);
		printf("\n\t\tI = 0\n");
		backMenu(x, y, n, 3,1);
	}
	else{
		printf("definida en [%f, %f]\n", x[0], x[n-1]);
		printf("\n\t\tI = %.8f\n", I);
		backMenu(x, y, n, 3,1);
	}

}

