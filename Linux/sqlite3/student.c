#include <stdio.h>
#include <stdlib.h>
//#include <sqlite3.h>

#define DATABASE "stu.db"

int do_insert(sqlit3 *db)
{
    int id;
    char name[32] = {};
    int score;
    char sql[128] = {};
    char *errmsg;

    printf("Input id: ");
    scanf("%d", &id);
    getchar();

    printf("Input name: ");
    scanf("%s", name);
    getchar();

    printf("Input score: ");
    scanf("%d", &score);
    getchar();

    sprint(sql, "insert into stu values(%d, '%s' %d);", id, name, score);

    if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK){
        printf("%s\n", errmsg);
    }else{
        printf("Insert success.\n");
    }
}

int do_delete(sqlit3 *db)
{
    int id;
    char sql[128] = {};
    char *errmsg;

    printf("Input id: ");
    scanf("%d", &id);
    getchar();

    sprint(sql, "delete from stu where id=%d", id);

    if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK){
        printf("%s\n", errmsg);
    }else{
        printf("Delete success.\n");
    }
}

int do_update(sqlit3 *db)
{
    int id;
    int score;
    char sql[128] = {};
    char *errmsg;

    printf("Input update id: ");
    scanf("%d", &id);
    getchar();

    printf("Update score: ");
    scanf("%d", &score);
    getchar();

    sprint(sql, "update stu set score = %d where id = %d", score, id);

    if(sqlite3_exec(db, sql, NULL, NULL, &errmsg) != SQLITE_OK){
        printf("%s\n", errmsg);
    }else{
        printf("Update success.\n");
    }
}

int callback(void *para, int f_num, char **f_value, char **f_name)
{
    int i = 0;

    for(i=0; i<f_num; i++){
        printf("%-11s", f_value[i]);
    }
    putchar(10);

    return 0;
}

int do_query(sqlit3 *db)
{
    char sql[128] = {};
    char *errmsg;

    sprint(sql, "select * from stu;");

    if(sqlite3_exec(db, sql, callback, NULL, &errmsg) != SQLITE_OK){
        printf("%s\n", errmsg);
    }else{
        printf("Query success.\n");
    }
}

int do_query(sqlit3 *db)
{
    char sql[128] = {};
    char *errmsg;
    char **resultp;
    int nrow;
    int ncloum;

    sprint(sql, "select * from stu;");

    if(sqlite3_exec(db, sql, &resultp, &nrow, &ncloum, &errmsg) != SQLITE_OK){
        printf("%s\n", errmsg);
    }else{
        printf("Query success.\n");
    }

    index = ncloumn;
    for(i = 0; i < nrow; i++)
    {
        for(j=0; j<ncloumn; j++)
        {
            printf("%-11s ", resultp[index++]);
        }
        putchar(10);
    }
    
    return 0;
}

int main(int argc, const char *argv[])
{
    sqlite3 *db;
    char *errmsg;
    int cmd;

    if(sqlite3_open(DATABASE, &db) != SQLITE_OK){
        printf("%s\n", sqlite3_errmsg(db));
        return -1;
    }else{
        printf("Open DATABASE success.\n");
    }

    // 创建一张数据库表格
    if(sqlite3_exec(db, "create table stu(id Integer, name char, score Integer);", NULL, NULL, &errmsg) != SQLITE_OK){
        printf("%s\n", errmsg);
    }else{
        printf("create table or open success.\n");
    }

    while(1)
    {
        printf("*****************************************\n");
        printf("1:insert 2:delete 3:query 4:update 5:quit.\n");
        printf("*****************************************\n");

        scanf("%d", &cmd);
        getchar();

        switch(cmd)
        {
            case 1:
                do_insert(db);
                break;
            case 2:
                do_delete(db);
                break;
            case 3:
                do_query(db);
                break;
            case 4:
                do_update(db);
                break;
            case 5:
                sqlite3_close(db);
                exit(0);

            default: break;
        }
    }

    return 0;
}