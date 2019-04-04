//#include "Calculadora.c"



int Calc_Suma(int nPrimerOperando, int nSegundoOperando){

    int ReturnSuma = 0;

    ReturnSuma = nPrimerOperando+nSegundoOperando;

    return ReturnSuma;
}


int Calc_Resta(int nPrimerOperando, int nSegundoOperando){


    int ReturnResta = 0;

    ReturnResta = nPrimerOperando-nSegundoOperando;

    return ReturnResta;

}



float Calc_Divicion (int nPrimerOperando, int nSegundoOperando){

    float ReturnDivicion;


    ReturnDivicion= (float)nPrimerOperando/(float)nSegundoOperando;


    return ReturnDivicion;
}

int Calc_Multiplicacion (int nPrimerOperando, int nSegundoOperando){

    int ReturnMultiplicacion;

    ReturnMultiplicacion = nPrimerOperando*nSegundoOperando;

    return ReturnMultiplicacion;


}



int Calc_Factorial (int nNumero){

    int i, nFact =1;

    for(i=1;i<=nNumero;i++){

        nFact = nFact*i;
    }

    return nFact;
}



/******************* LISTAR *********************/



void Calc_Mostrar(int nSuma, int nResta, float fDivicion, int nMultiplicacion,int nFactorialA, int nFactorialB,int nPrimerOperando, int nSegundoOperando,int flag){


    printf("El Resultado de (%d+%d) = %d\n",nPrimerOperando,nSegundoOperando,nSuma);
    printf("El Resultado de (%d-%d) = %d\n",nPrimerOperando,nSegundoOperando,nResta);

    if(flag==0){
    printf("El Resultado de (%d/%d) = %.2f\n",nPrimerOperando,nSegundoOperando,fDivicion);
    }else{
    printf("No se puede dividir por 0 (cero)\n");
    }

    printf("El Resultado de (%d*%d) = %d\n",nPrimerOperando,nSegundoOperando,nMultiplicacion);
    printf("El Factorial de %d = %d\n",nPrimerOperando,nFactorialA);
    printf("El Factorial de %d = %d\n",nSegundoOperando,nFactorialB);
}



/*************** OTROS ****************/



int ValidarRango(int nOpcion,int nMaximo,int nMinimo){


    while (nOpcion < nMinimo || nOpcion > nMaximo){

        printf("Rango invalido, ingrese entre %d y %d: ",nMinimo,nMaximo);
        scanf("%d",&nOpcion);
    }

    return nOpcion;

}

