#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

double sigmoid(double value);
double perceptron(double * entrada, double * pesos,int n_entradas);
double rede(double * entrada, double * pesos_p1, double * pesos_p2, double * poses_po, int n_entradas);
int loadFeatureDataset(char * FileName, int features, int classes , double dataset[][features], int * labels, int max_samples,int verbose);
int loadFeatures( FILE *stream,double * dataset, int * label, int n_features, int verbose);
float exatidao(int vp, int vn, int fp, int fn);
float recall(int vp, int vn, int fp, int fn);
float precisao(int vp, int vn, int fp, int fn);
float f1(int vp, int vn, int fp, int fn);
void printEvalMetric(float exatidao, float precisao, float recall, float f1);
void printMatrizConfusao(int vp, int vn, int fp, int fn);
void eval(double * previsao, int * target, int n);
void vizClusters(char *ficheiro, int n_samples, double *x, double *y, double *z, int *labels, double *y_pred);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);





int main(){
    int N_FEATURES = 6;
    int N_CLASSES = 1;
    int max_samples = 40;
    double Inputs[max_samples][N_FEATURES];
    int Targets[max_samples];
    //double Output[max_samples][N_CLASSES];
    double mx[max_samples],my[max_samples],mz[max_samples],vx[max_samples],vy[max_samples],vz[max_samples];

    double pesos_p1[] = {2.981465,-0.469540, 0.282919, -3.160719,0.431559, -0.181928 ,  -0.583663};
    double pesos_p2[] = {1.342612,-0.158436 , 0.073571 ,-0.221724 ,-6.347154, -10.661768 , 19.218855 };
    double poses_po[] = {-7.215086,-9.565978,20.784457};

    printf("Loading Features ...\n");
    

    // copy to the new format

   

    vizClusters("ClusterClassificationViz.html",n_samples,mx,my,mz,Targets,previsao);

    // Avaliação
    eval(previsao,Targets,n_samples);

}




void vizClusters(char *ficheiro, int n_samples, double *x, double *y, double *z, int *labels, double *y_pred){

    FILE *fp  = fopen (ficheiro, "w");
    if(fp==NULL){
        printf("Nao e' possivel criar o ficheiro\n");
        return;
    }
    int colorR[2],colorG[2],colorB[2];
    colorR[0]=0,colorG[0]=0,colorB[0]=255,colorR[1]=0,colorG[1]=255,colorB[1]=0;

    fprintf(fp,"<head>\n");
    fprintf(fp,"    <script src='https://cdn.plot.ly/plotly-2.16.1.min.js'></script>\n");
    fprintf(fp,"    <script src='https://cdnjs.cloudflare.com/ajax/libs/d3/3.5.17/d3.min.js'></script>\n");
    fprintf(fp,"</head><body>\n<div id='myDiv' style='width: 99%%;height:99%%'></div>\n");
    fprintf(fp,"<script>\n");
    for(int j=0;j<n_samples;j++){
        fprintf(fp,"var Cluster%d = { x:[%lf], y:[%lf], z:[%lf],",j,x[j],y[j],z[j]);
        fprintf(fp,"   mode: 'markers',\n");
        fprintf(fp,"    marker: { size: 5,\n");
        int y_p=y_pred[j]>0.5?1:0;
        fprintf(fp,"        color: 'rgba(%d, %d, %d, 0.8)',\n",colorR[y_p],colorG[y_p],colorB[y_p]);
        if(y_p!=labels[j]){
            fprintf(fp,"symbol: 'x',\n");
        }
        fprintf(fp,"        line: { width: 1.5}, opacity: 0.8}, type: 'scatter3d' };\n");
    }
    fprintf(fp,"    var scaleUP = { x: [80], y: [80], z: [80], mode: 'markers',\n");
    fprintf(fp,"        marker: { color: \"rgba(255, 255, 255, 0)\"}, type: 'scatter3d' };\n");
    fprintf(fp,"    var scaleDOWN = { x: [-80], y: [-80], z: [-80], mode: 'markers',\n");
    fprintf(fp,"        marker: {color: \"rgba(255, 255, 255, 0)\"}, type: 'scatter3d' };\n");

    fprintf(fp,"var data = [");
    for(int j=0;j<n_samples;j++){
        fprintf(fp,"Cluster%d ,",j);
    }
    fprintf(fp,"scaleUP,scaleDOWN];\n");
    fprintf(fp,"var layout = {showlegend:false,showgrid: false,hovermode : 'x',margin: {  l: 0, r: 0, b: 0, t: 0\n");
    fprintf(fp,"  }, xaxis: {autorange: false,scaleratio: 1,range: [-80, 80]}, yaxis: {autorange: false,scaleratio: 1,range: [-80, 80]}, zaxis: {autorange: false,scaleratio: 1,range: [-80, 80]}};\n");
    fprintf(fp,"Plotly.newPlot('myDiv', data, layout);\n</script>\n</body>\n");

    fclose(fp);
}



