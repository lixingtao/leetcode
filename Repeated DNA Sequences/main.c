#include <stdio.h>
#include <stdlib.h>

#define maxn (1024*1024)
#define MAP 
#define MAXN 200000
#define MAXHASH 100003

int Hash(char * s,int start){
    int ret=0;
    int i;
    for(i=start;i<start+10;i++){
	ret=ret<<2;
	switch(s[i]){
	    case 'A': ret+=0;break ;
	    case 'C': ret+=1;break ;
	    case 'G': ret+=2;break;
	    case 'T': ret+=3;break;
	    default :return -1;
	}
    }
    return ret;
}

void charCopy(char *s,char *t){
    int i=0;
    for(;i<10;i++)s[i]=t[i];
    s[i]='\0';
}

#ifdef MAP
int st[MAXN];
int head[MAXHASH];
char vis[MAXN];
int next[MAXN];

char ** findRepeatedDnaSequences(char *input ,int *outputSize){
    int i,len,h,H;
    int u;
    int curStateNum=0;
    int totSize=10000;
    char **ret=(char **)malloc(totSize*sizeof(int));
    *outputSize=0;

    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    for(len=0;input[len];len++);

    for(i=0;i<=len-10;i++){
	h=Hash(input,i);
	H=h%MAXHASH;
	u=head[H];
	while(u!=-1){
	    if(st[u]==h)break;
	    u=next[u];
	}
	if(u!=-1){ ///找到重复的子串
	    if(vis[u])continue;
	    vis[u]=1;
	    if(*outputSize>=curStateNum){
		    totSize+=10000;
		    ret=(char**)realloc(ret,totSize*sizeof(int));
	    }
	    ret[*outputSize]=(char *)malloc(11*sizeof(char));
	    charCopy(ret[*outputSize],input+i);
	    (*outputSize)++;
	}
	else{
	    st[curStateNum]=h;
	    next[curStateNum]=head[H];
	    head[H]=curStateNum;
	    curStateNum++;
	}
    }
    return ret;
}
#endif

#ifndef MAP
char mmap[maxn];

char ** findRepeatedDnaSequences(char *input ,int *outputSize){
    int i,len,h;
    int totSize=10000;
    char **ret=(char **)malloc(totSize*sizeof(int));
    *outputSize=0;

    memset(mmap,0,sizeof(mmap));
    for(i=0;input[i+9];i++){
	h=Hash(input,i);
	if(!mmap[h])mmap[h]=1;
	else{
	    if(mmap[h]==1){
		mmap[h]=-1;
		if(*outputSize>=totSize){
		    totSize+=10000;
		    ret=(char**)realloc(ret,totSize*sizeof(int));
		}
		ret[*outputSize]=(char *)malloc(11*sizeof(char));
		charCopy(ret[(*outputSize)++],input+i);
	    }
	}
    }
    return ret;
}
#endif

int main()
{
    char s[100000];
    int outlen;
    char **vet;
    int i;
    freopen("in.dat","r",stdin);
    scanf("%s",s);
    vet=findRepeatedDnaSequences(s,&outlen);
    for(i=0;i<outlen;i++)printf("%s\n",vet[i]);
    return 0;
}
