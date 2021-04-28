char* strcpy(char* strDest, const char* strSrc){
    int i;
    for(i=0; strSrc[i]!='\0'; i++){
        strDest[i]=strSrc[i];
    }
    strDest[i]='\0';
    return strDest;
}
