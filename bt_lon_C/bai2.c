#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int w;
    int v;
    int q;
    float unitVal;
    char name;
} Obj;

int compr(const void *ptr1, const void *ptr2)
{
    Obj obj1 = *(Obj *)ptr1;
    Obj obj2 = *(Obj *)ptr2;
    return (obj1.unitVal < obj2.unitVal) - (obj1.unitVal > obj2.unitVal);
}

void printObj(Obj obj)
{
    printf("%c(%d,%d) : %d \n", obj.name, obj.w, obj.v, obj.q);
}

int main()
{
    int N, T;
    FILE *inp = NULL;
    inp = fopen("BAG.INP", "r");
    if (inp != NULL)
        return 1;
    fscanf(inp, "%d %d", &N, &T);
    Obj *objs = (Obj *)malloc(N * sizeof(Obj));

    for (int i = 0; i < N; i++)
    {
        Obj tmp;
        fscanf(inp, "%d %d %c", &tmp.w, &tmp.v, &tmp.name);
        tmp.unitVal = (float)(tmp.v) / (float)(tmp.w);

        objs[i] = tmp;
    }

    qsort(objs, N, sizeof(Obj), compr);

    int cur_w = T;
    int cur_v = 0;

    for (int i = 0; i < N; i++)
    {
        div_t divRet = div(cur_w, objs[i].w);
        int quan = divRet.quot;
        cur_v += quan * objs[i].v;
        cur_w = divRet.rem;

        objs[i].q = quan;

    }

    printf("%d \n", cur_v);
    for (int i = 0; i < N; i++)
    {
        if (!objs[i].q)
            continue;
        printf("%c %d \n", objs[i].name, objs[i].q);
    }

    fclose(inp);
    free(objs);
    return 0;
}
