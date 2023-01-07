
#include <stdio.h>
#include <math.h>

double sigmoid(double value);
double perceptron(double * entrada, double * pesos,int n_entradas);
void camada2p(double * entrada, double * pesos_p1, double * pesos_p2, int n_entradas, double * y);
double rede(double * entrada, double * pesos_p1, double * pesos_p2, double * poses_po, int n_entradas);


int main(){
    double w1[] = {2.981465,-0.469540, 0.282919, -3.160719,0.431559, -0.181928 ,  -0.583663};
    double w2[] = {1.342612,-0.158436 , 0.073571 ,-0.221724 ,-6.347154, -10.661768 , 19.218855 };
    double wo[] = {-7.215086,-9.565978,20.784457};

    double fp[] = {48.538208, 9.440077, 1.102703, 0.021723, 0.059699, 0.456924};
    double fn[] = {57.936264, 12.603884, 1.997085, 0.051343, 0.149340, 0.046218};
    int n = 6;
    
    double sigvalue = 0;
    double y_value = 0 ;
    double y[2];
    
   
    printf("Produto Escalar: %lf\n",score);
    
    
   
}
