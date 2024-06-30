#include <stdio.h>
#include <math.h>
#define MAX 10
#define SIZE 100


float Fx(float , int , float []);
float F1x(float , int , float []);
void katsayial();
void Bisection();
void Regula_Falsi();
void Newton_Rapshon();
void matris_Tersi();
void Gauss_Eleminasyon();
void Gauss_Seidal();
void Sayisal_Turev();
void Simpson();
void Trapez();
void Gregory_Enterpolasyonu();

int sec;

int main(){
	int choice, devam = 1;;
	
	
	while(devam == 1){
		printf("\n");
		printf("********** Hesaplama Yontemleri ***********\n\n");
		printf("\n1-Bisection\n");
		printf("\n2-Regula-Falsi\n");
		printf("\n3-Newton-Rapshon\n");
		printf("\n4-NxN'lik bir matrisin tersi\n");
		printf("\n5-Gauss Eleminasyon\n");
		printf("\n6-Gauss Seidal\n");
		printf("\n7-Sayisal Turev (merkezi, ileri ve geri)\n");
		printf("\n8-Simpson yontemi\n");
		printf("\n9-Trapez yontemi\n");
		printf("\n10-Gregory Newton Enterpolasyonu\n");
		printf("\n0-Cikis\n\n");
		printf("\n**************************************************\n");
		printf("lutfen menuden bir secim yapiniz : ");
		scanf("%d", &choice);
		
		
		
		switch(choice){
			case 1:
				Bisection();
				break;
			case 2:
				Regula_Falsi();
				break;
			case 3:
				Newton_Rapshon();
				break;
			case 4:
				matris_Tersi();
				break;
			case 5:
				Gauss_Eleminasyon();
				break;
			case 6:
				Gauss_Seidal();
				break;
			case 7:
				Sayisal_Turev();
				break;
			case 8:
				Simpson();
				break;
			case 9:
				Trapez();
				break;
			case 10:
				Gregory_Enterpolasyonu();
				break;	
			case 0:
				devam = 0;
				break;	
			default:
				printf("\n\tHatali secim lutfen bir daha deneyin\n");
				break;	
			
		}
	}
	
	return 0;
}

float Fx(float x, int derece, float katsayilar []){ // fx fonksiyonu olusturma
    int i;
    float F = 0;

    for(i=derece;i>=0;i--){
        F += katsayilar[i]*pow(x,i);
    }

    return F;
}

float F1x(float x, int derece, float katsayilar[]){   //fx fonksiyonunun türevini olusturma
	int i;
	float F = 0;
	
	for(i=derece;i>0;i--){
		F += katsayilar[i]*i*pow(x,i-1);
	}
	
	return F;
}

void katsayial(int derece,float katsayilar[]){   		//katsayilari alma
int i;

for(i=derece;i>=0;i--){
        printf("%d. dereceden x'in katsayisini giriniz :", i);
        scanf("%f", &katsayilar[i]);
    }
}
    
void Bisection(){
    system("cls");
    
    float katsayilar[MAX];
    float a, b, c, Fa, Fb, Fc = 1;
    float ep = 0.01, hata = 1;
    int i, derece, count = 0;
    int sart=1;

    printf("**********Bisection Yontemi***********\n\n");
    printf("Fonksiyon kacinci derece : ");
    scanf("%d", &derece);

	katsayial(derece,katsayilar);
   
    printf("Aralik giriniz [a,b]: ");
    scanf("%f %f", &a, &b);
    
    printf("Epsilon degeri giriniz : ");
    scanf("%f", &ep);

    Fa = Fx(a,derece,katsayilar);
    Fb = Fx(b,derece,katsayilar);
    
    if(Fa * Fb > 0 || b<=a){
        printf("Error: F(a) * F(b) < 0 ve b > a olmali\n");
        printf("\n\n");
        printf("Tekrar hesaplamak icin 1'e basin: \nAna menuye donmek icin herhangi bir tusa basin: ");
        scanf("%d",&sec);
        printf("\n\n");
        if (sec==1)
            Bisection();
        system("cls");
        return;
    }

    while(hata > ep && sart==1){
        c = (a+b)/2;   // orta nokta belirleme
        count++;
        Fa = Fx(a,derece,katsayilar);
        Fc = Fx(c,derece,katsayilar);
        
        if(Fc == 0){
            sart=0;
        }else if(Fa*Fc < 0){
            b = c;
        }else{
            a = c;
            Fa = Fc;
        }
        hata = (b-a)/pow(2,count);
    }

    printf("Kok(c) = %f\niterasyon = %d", c, count);
    printf("\n\n");
    printf("Tekrar hesaplamak icin 1'e basin: \nAna menuye donmek icin herhangi bir tusa basin: ");
    scanf("%d",&sec);
    printf("\n\n");
    if (sec==1)
        Bisection();
    system("cls");
}

void Regula_Falsi(){
	system("cls");
	
	float katsayilar[MAX];
    float a, b, c, Fa, Fb, Fc = 1;
    float ep = 0.01, hata,x;
    int i, derece, count = 0;

	printf("**********Regula-Falsi Yontemi***********\n\n");
    printf("Fonksiyon kacinci derece : ");
    scanf("%d", &derece);

    katsayial(derece,katsayilar);

    printf("Aralik giriniz [a,b]: ");
    scanf("%f %f", &a, &b);
    
    printf("Epsilon degeri giriniz : ");
    scanf("%f", &ep);

    Fa = Fx(a,derece,katsayilar);
    Fb = Fx(b,derece,katsayilar);
    
    if(Fa * Fb <= 0 && b>a){
    	
    	if(Fa*Fb != 0){
		    i = 1;
		    hata = (b-a)/(2*i);
		    while (hata > ep){
		        x = c;
		        hata = (b-a)/(2*i);
		        i *= 2;
		        count ++;
		
		        Fa = Fx(a,derece,katsayilar);
		        Fb = Fx(b,derece,katsayilar);
		        
		        c = (b*Fa - a*Fb)/(Fa-Fb);
		        
		        Fc = Fx(c,derece,katsayilar);
		
		        if(Fa*Fc > 0){
		            a = c;
		        }else if(Fb*Fc > 0){
		            b = c;
		        }
		        
		    }
		}else{
			if(Fa == 0){
				c = a;
			}else{
				c = b;
			}
		}
	    printf("c = %f \niterasyon = %d\n", c, count);
	
	}else{
		printf("Error: F(a) * F(b) < 0 ve b > a olmali\n");
	}
	printf("\n\n");
	printf("Tekrar hesaplamak icin 2'ye basin: \nAna menuye donmek icin herhangi bir tusa basin: ");
	scanf("%d",&sec);
	printf("\n\n");
	if (sec==2)
	Regula_Falsi();
	
	system("cls");
}

void Newton_Rapshon(){
	system("cls");
	
	float katsayilar[MAX];
	float x1, x2, hata = 1, ep=0.1;
	float Fa, m;
	int derece, count = 0;
	int i;
	
	printf("**********Newton Rapshon Yontemi***********\n\n");
	printf("Fonksiyon kacinci derece : ");
    scanf("%d", &derece);

    katsayial(derece,katsayilar);
    
    printf("Baslangic degeri giriniz : ");
    scanf("%f", &x1);
    
    printf("Epsilon degeri giriniz : ");
    scanf("%f", &ep);
    
    Fa = Fx(x1,derece,katsayilar);
	m = F1x(x1,derece,katsayilar); //turevi
    
    do{
    	Fa = Fx(x1,derece,katsayilar);
	    m = F1x(x1,derece,katsayilar);
	    
	    x2 = x1-(Fa/m);
	    
	    hata = fabs(x2-x1); //mutlak deger fark
	    x1 = x2;
	    count++;
    	
	}while(hata>ep);
	
	printf("Kok = %.8f \ndegeri = %f \niterasyon = %d", x1, Fa, count);

	printf("\n\n");
	
	printf("Tekrar hesaplamak icin 3'e basin: \nAna menuye donmek icin herhangi bir tusa basin: ");
	scanf("%d",&sec);
	printf("\n\n");
	if (sec==3)
	Newton_Rapshon();
	
	system("cls");
}

void matris_Tersi(){
	system("cls");
	/*
	NOT: matrisin kosegen elmankari 0'dan farkli olmali
	*/
	
	float matris[SIZE][SIZE], inv_matris[SIZE][SIZE];
	int n, err = 0;
	int i,j,k;
	
	printf("**********Matrisin Tersi Bulma***********\n\n");
	printf("Matris mertebesini giriniz : ");
	scanf("%d", &n);

//matris okuma	
	printf("Matris elemanlarini giriniz\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%f", &matris[i][j]);
		}
		if(matris[i][i] == 0){  // kosegen kontrolu
			err = 1;
		}
	}

	if(err == 0){
	
	//birim matrisi saga ekleyip degeleri 0 ve 1 atama	
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==j){
					inv_matris[i][j] = 1;
				}else{
					inv_matris[i][j] = 0;
				}
			}
		}
	
	//tersini alma
		for(i=0;i<n;i++){
			for(k=0;k<n;k++){
			    if(k!=i){
				    matris [i][k] /= matris[i][i];   
				}
				inv_matris[i][k] /= matris[i][i];
			}
			matris [i][i] = 1; 
			
			for(j=0;j<n;j++){
				if(j != i){
					for(k=0;k<n;k++){
						if(k!=i){
							matris[j][k] -= matris[j][i]*matris[i][k];
						}
						inv_matris[j][k] -= matris[j][i]*inv_matris[i][k];
					}
					matris[j][i] = 0;
				}
			}
		}
	//tersi yazdirma
		printf("\nTers matris\n");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%7.4f ", inv_matris[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("Error: matrisin kosegen elmankari 0'dan farkli olmali!");
	}
	printf("\n\n");
	
	printf("Tekrar hesaplamak icin 4'e basin: \nAna menuye donmek icin herhangi bir tusa basin: ");
	scanf("%d",&sec);
	printf("\n\n");
	if (sec==4)
	matris_Tersi();
	
	system("cls");
}

void Gauss_Eleminasyon(){
	system("cls");
	
	float katsayi[SIZE][SIZE], sonuclar[SIZE];
	int n, err = 0;
	int i,j,k;
	
	printf("**********Gauss Eleminasyon Yontemi***********\n\n");
	printf("Denklem sayisini giriniz : ");
	scanf("%d", &n);

//matris okuma	
	for(i=0;i<n;i++){
		printf("%d. denklemin degisken katsayilarini giriniz : \n",i+1);
		for(j=0;j<n;j++){
			scanf("%f", &katsayi[i][j]);
		}
		if(katsayi[i][i] == 0){
			err = 1;
		}
	}

	if(err == 0){

		printf("Sonuc degerleri giriniz\n");
		for(i=0;i<n;i++){
			printf("c%d:",i+1);
			scanf("%f", &sonuclar[i]);
		}
	
	//gauss Eleminasyon kurali ile cozum
		for(i=0;i<n;i++){
			for(k=0;k<n;k++){
			    if(k!=i){
				    katsayi [i][k] /= katsayi[i][i];   
				}
			}
			sonuclar[i] /= katsayi[i][i];
			katsayi [i][i] = 1;
			for(j=0;j<n;j++){
				if(j != i){
					for(k=0;k<n;k++){
						if(k!=i){
							katsayi[j][k] -= katsayi[j][i]*katsayi[i][k];
						}
					}
					sonuclar[j] -= katsayi[j][i]*sonuclar[i];
					katsayi[j][i] = 0;
				}
			}
		}
	
		printf("\ncozum :\n");
		for(i=0;i<n;i++){
				printf("x%d = %.2f\n", i+1, sonuclar[i]);
		}
	}else{
		printf("Error: matrisin kosegen elmankari 0'dan farkli olmali!");	
	}
	
	printf("Tekrar hesaplamak icin 5'e basin: \nAna menuye donmek icin herhangi bir tusa basin: ");
	scanf("%d",&sec);
	printf("\n\n");
	if (sec==5)
	Gauss_Eleminasyon();
	
	system("cls");
}

void Gauss_Seidal(){
	system("cls");
	
	float katsayi[SIZE][SIZE], sonuclar[SIZE], degerler[SIZE], farklar[SIZE];
	float tmp;
	int n;
	int devam = 1;
	float toplam, ep = 0.001;
	int i, j;
		
	printf("**********Gauss Seidal Yontemi***********\n\n");
	printf("Denklem sayisini giriniz : ");
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		printf("%d. denklemin bilinmeyen katsayilarini giriniz : \n",i+1);
		for(j=0;j<n;j++){
			scanf("%f", &katsayi[i][j]);
		}
	}
	
	printf("Sonuc degerleri giriniz\n");
	for(i=0;i<n;i++){
		printf("c%d:",i+1);
		scanf("%f", &sonuclar[i]);
	}
	
	printf("Baslangic degerleri giriniz\n");
	for(i=0;i<n;i++){
		printf("x%d:",i+1);
		scanf("%f", &degerler[i]);
	}
	
	printf("Hata degeri giriniz : ");
	scanf("%f", &ep);

	while(devam == 1){
		
		for(i=0;i<n;i++){
			toplam = 0;
			for(j=0;j<n;j++){
				if(i!=j){
					toplam += katsayi[i][j]*degerler[j];
				}
			}
			tmp = degerler[i];
			degerler[i] = (sonuclar[i] - toplam)/katsayi[i][i];
			farklar[i] = fabs(degerler[i]-tmp);
		}
		
		
		i=0;
		devam = 0;
		while(i<n && devam == 0){
			if(farklar[i]>ep){
				devam = 1;
			}
			i++;	
		}
		
	}
	
	for(i=0;i<n;i++){
		printf("x%d = %f\n", i+1, degerler[i]);
	}
	
	printf("Tekrar hesaplamak icin 6'ya basin: \nAna menuye donmek icin herhangi bir tusa basin: ");
	scanf("%d",&sec);
	printf("\n\n");
	if (sec==6)
	Gauss_Seidal();
	
	system("cls");
}

void Sayisal_Turev(){
	system("cls");
	
	float katsayilar[MAX];
	float x, h, DF;
	int i, derece;
	
	printf("**********Sayisal Turev***********\n\n");
	printf("Fonksiyon kacinci derece : ");
    scanf("%d", &derece);

   katsayial(derece,katsayilar);
    
    printf("Turevini bulmak istediginiz noktayi giriniz : ");
    scanf("%f", &x);
    
    printf("h degerini giriniz : ");
    scanf("%f", &h);
    
    
    DF = (Fx(x,derece,katsayilar) - Fx(x-h,derece,katsayilar))/h;
	printf("geri farklar ile turev    \t= %.6f\n\n", DF);

	DF = (Fx(x+h,derece,katsayilar) - Fx(x,derece,katsayilar))/h;
	printf("ileri farklar ile turev   \t= %.6f\n\n", DF);
	
	DF = (Fx(x+h,derece,katsayilar) - Fx(x-h,derece,katsayilar))/(2*h);
	printf("merkezi farklar ile turev \t= %.6f\n\n", DF);
	
	printf("Tekrar hesaplamak icin 7'ye basin: \nAna menuye donmek icin herhangi bir tusa basin: ");
	scanf("%d",&sec);
	printf("\n\n");
	if (sec==7)
	Sayisal_Turev();
	
	system("cls");
}

void Simpson(){
	system("cls");
	
	float katsayilar[MAX];
	float a, b, h, I;
	int n, derece;
	int i;
	
	printf("**********Simpson Yontemi***********\n\n");
	printf("Fonksiyon kacinci derece : ");
    scanf("%d", &derece);

    katsayial(derece,katsayilar);
    
    printf("Integralini bulmak istediginiz araligi giriniz [a,b]: ");
    scanf("%f %f", &a, &b);
    
    printf("Aralikta parca sayisini giriniz (cift sayi olmali): ");
    scanf("%d", &n);
    
    h = (b-a)/n;
    I= (Fx(a,derece,katsayilar) + Fx(b,derece,katsayilar));

	for(i=1;i<n;i++){
		if(i%2==1){
			I += 4*Fx(a+(h*i),derece,katsayilar);
		}else{
			I += 2*Fx(a+(h*i),derece,katsayilar);
		}
		//printf("integral = %.2f\n", I*h/3);
	}
	I *= (h/3);
	printf("integral = %.4f\n", I);
	
	printf("Tekrar hesaplamak icin 8'e basin: \nAna menuye donmek icin herhangi bir tusa basin: ");
	scanf("%d",&sec);
	printf("\n\n");
	if (sec==8)
	Simpson();
	
	system("cls");
}

void Trapez(){
	system("cls");
	
	float katsayilar[MAX];
	float a, b, h, I;
	int n, derece;
	int i;
	
	printf("**********Trapez Yontemi***********\n\n");
	printf("Fonksiyon kacinci derece : ");
    scanf("%d", &derece);

    katsayial(derece,katsayilar);
    
    printf("Integralini bulmak istediginiz araligi giriniz [a,b]: ");
    scanf("%f %f", &a, &b);
    
    printf("Aralikta parca sayisini giriniz : ");
    scanf("%d", &n);
    
    h = (b-a)/n;
    I= (Fx(a,derece,katsayilar) + Fx(b,derece,katsayilar))/2;
    for(i=1;i<n;i++){
    	I += Fx(a+(h*i),derece,katsayilar);
	}
	I *= h;
	printf("integral = %.2f\n", I);
	
	
	printf("Tekrar hesaplamak icin 9'a basin: \nAna menuye donmek icin herhangi bir tusa basin: ");
	scanf("%d",&sec);
	printf("\n\n");
	if (sec==9)
	Trapez();
	
	system("cls");
}

void Gregory_Enterpolasyonu(){
	system("cls");
	
	float x_ler[SIZE], y_ler[SIZE][SIZE] = {0};
	float x, h, payda, faktoryel, tmp;
	float sonuc;
	int n, m, count, devam = 1;
	int i, j;
	
	printf("**********Gregory Newton Enterpolasyonu***********\n\n");
	printf("Kac tane X degeri var : ");
	scanf("%d", &n);
	
	printf("ilk X degeri : ");
	scanf("%f", &x_ler[0]);
	
	printf("X degerleri arasindaki fark (h) : ");
	scanf("%f", &h);
	
	for(i=1;i<n;i++){
		x_ler[i] = x_ler[i-1] + h;
	}
	
	for(i=0;i<n;i++){
		printf("f(%.1f) Y degeri giriniz giriniz : ",x_ler[i]);
		scanf("%f", &y_ler[i][0]);
	}
	
	printf("Bulmak istediginiz X degeri giriniz : ");
	scanf("%f", &x);
	
	m = 1;
	while(devam == 1 && m<n){
		
		for(i=0;i<n-1;i++){
			y_ler[i][m] = y_ler[i+1][m-1] - y_ler[i][m-1];
		}
		i=0;
		devam = 0;
		while(i<n-m-1 && devam == 0){
			if( (y_ler[i][m]) != (y_ler[i+1][m]) ){
				devam = 1;
			}
			i++;	
		}
		m++;
	}
	
	printf("\n");
	for(i=0;i<n;i++){
		j = 0;
		while(j<n-i && j<m){
			printf("%8.2f | ",y_ler[i][j]);
			j++;
		}
		printf("\n");
	}

	sonuc = 0;
	faktoryel = 1;
	for(i=0;i<m;i++){
		if(i!=0){
			faktoryel *= i;
		}
		tmp = 1;
		for(j=0;j<i;j++){
			tmp *= (x-x_ler[j]);
		}
		sonuc += (y_ler[0][i] * tmp) / (pow(h,i)*faktoryel);
	}
	
	printf("\n\nsonuc = %.6f\n", sonuc);
	
	printf("Tekrar hesaplamak icin 10'a basin: \nAna menuye donmek icin herhangi bir tusa basin: ");
	scanf("%d",&sec);
	printf("\n\n");
	if (sec==10)
	Gregory_Enterpolasyonu();
	
	system("cls");
}

