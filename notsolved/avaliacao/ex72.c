#include <stdio.h>
float exatidao(int vp, int vn, int fp, int fn){
// ================================
// codigo alinea 3.2.2b)
// Faca o codigo aqui
    return 0;
// ================================

}
float recall(int vp, int vn, int fp, int fn){
// ================================
    //codigo alinea 3.2.2b)
    // Faca o codigo aqui
    return 0;
// ================================
}
float precisao(int vp, int vn, int fp, int fn){
// ================================
    // codigo alinea 3.2.2b)
    // Faca o codigo aqui
    return 0;
// ================================
}
float f1(int vp, int vn, int fp, int fn){
// ================================
    // codigo alinea 3.2.2b)
    // Faca o codigo aqui
    
    return 0;
// ================================
}

void printEvalMetric(float exatidao, float precisao, float recall, float f1){
    // ================================
    // codigo alinea 3.2.2b)
    // Mostrar metricas na linha de comandos

    //===============================
}

void printMetrizConfusao(int vp, int vn, int fp, int fn)
{
    // ================================
    // codigo alinea 3.2.1b)
    // Mostrar a matriz de confusao

    
}

int main () {
    int previsao[] = {0, 1, 0, 0, 1};
    int y[] = {1, 0, 1, 0, 1};
    int n = 5;
    int vp = 0,vn = 0, fn = 0, fp = 0;
    float e=0, r=0, p=0,f=0;

    //=========================================
    // codigo alinea 3.2.1a)
    printf("\ncodigo alinea 3.2.1a)\n");
    //Faça codigo aqui


   
    printf("vp = %d\n",vp);
    printf("vn = %d\n",vn);
    printf("fn = %d\n",fn);
    printf("fp = %d\n",fp);
    
    // ========================================

    printf("\ncodigo alinea 3.2.1b)\n");
    printMetrizConfusao(vp,vn,fp,fn);

    //=========================================
    printf("\ncodigo alinea 3.2.2a)\n");
    e = exatidao(vp,vn,fp,fn);
    r = recall(vp,vn,fp,fn);
    p = precisao(vp,vn,fp,fn);
    f = f1(vp,vn,fp,fn);

    //=========================================
    printf("\ncodigo alinea 3.2.2b)\n");
    printEvalMetric(e, p, r, f);

}