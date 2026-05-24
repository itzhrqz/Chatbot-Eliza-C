#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/*
Headers essenciais ao projeto
*/

/*
Este código serve como um chatbot que numa fase inicial, para qualquer base de dados .dat com perguntas e respostas
o bot consegue aprender sozinho e numa segunda fase o user pode falar com o bot sendo que este reage com base nos
conteúdos da base de dados eliza.dat

Ao contrário da fase anterior, nós agora somos alunos super inteligentes e já sabemos usar alocação de memória dinâmica,
o que também dispensa o uso das constantes ENTRIES_MAX e STRING_LEN_MAX.
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡠⠤⠔⠒⠒⠋⠉⠉⠉⠙⠒⠒⠢⠤⢄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⠖⠫⠁⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀ ⠉⠒⢤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡠⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⠉⠳⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡴⠋⠀⠀⠀⠀⠀⠀⠀⢀⠀⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀ ⠀ ⢀⣿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠎⡠⠀⠀⠀⠀⠀⣀⣠⣶⡿⠀⡇⢶⣤⣄⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⢸⣿⣿⣿⣷⣄⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡴⠁⡜⠁⠶⠴⠶⠾⠟⠛⠋⠉⣦⠀⠀⠈⠙⠛⠛⠛⠛⠛⠛⠛⠛⠉⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣧⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡜⠁⣸⠀⠀⠀⠀⠀⠀⠀⠀⣀⣾⠋⠀⠀⠀⠀⣀⣀⣀⣀⣀⣀⣀⣀⠀⠀⠀⠀⠀⠀⢠⡀  ⢸⣿⣿⣿⣿⣿⣧⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡸⠁⢠⢷⠀⢀⣀⣤⣤⢶⣾⣿⣿⠁⠀⠀⠀⠀⠀⠹⡏⠉⠉⠉⠉⠛⣿⣿⣿⣶⣤⣀⡀⢈⣧⠀⣿⣿⣿⣿⣿⣧⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⠇⠀⢸⣠⣴⢾⠋⠁⠠⣾⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⡇⢠⠀⠀⠀⢿⣿⣿⣿⠇⠙⠫⢿⣿⠟⠀⠘⣿⣿⣿⣿⣿⣿⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⠀⠀⠀⠿⠛⠚⠛⠋⠭⠭⠭⠩⠽⠶⠀⠀⠀⠀⠀⣤⣿⣶⣚⣛⣛⣛⠛⠛⠛⢓⣲⡶⠿⢿⣆⠀⠀⠹⢿⡟⣿⣿⣿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠇⠀⠀⠊⡅⠉   ⢹⣿⣿⣿⣿⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀     ⣿⣿⣿⣿
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠠⠤⠤⠤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⢹⣿⣿⣿⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⠀⠀⠀⠀⠀⢀⡼⠓⠺⠿⠶⡛⢛⡻⣿⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀   ⠘⡏⣿⣿⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⡇⠀⠀⠀⠀⠀⠀⢸⠿⣿⣶⡷⣶⣿⣿⣿⢬⢿⠆⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀  ⢰⠃⣿⣿⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣦⡀⠀⠀⠀⠀⢸⣷⣶⣤⣥⣵⣤⣤⣤⡈⢿⡆⠀⠀⠀⢀⣤⣾⣿⣿⣿⣿⡻⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡏⢀⡆⣴⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⣦⡀⠀⠀⠈⠈⠛⠿⠿⠿⠿⠿⠛⠃⠘⠃⠀⠀⣰⣿⣿⣿⣿⡿⠟⠛⠁ ⣴⠒⢦⠀⠀⠀⢀⡜⠀⣼⣧⢿⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⣿⣿⣶⣴⣶⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⠋⠀⠀⠀⠀⠀⢸⣿⠀⢸⡀⠀⠀⢀⡞⢀⡼⣽⢏⠏⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⣿⡇⠀⠀⠀⠀⠀⠀⠈⢸⠀⠀⣇⠀⣠⢋⣤⣪⡾⣫⠎⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⣿⡿⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⣿⠏⠀⠀⠀⠀⠀⠀⠀⠀⠸⡄⠀⠸⣤⠞⠻⢛⣿⡯⠞⠁⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⢠⡞⠓⢦⡠⠔⠒⠓⠒⠒⠽⢄⡀⠉⠁⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠑⠦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠳⣄⢫⣀⣀⣤⠤⠤⠤⢤⡀⠹⣆⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠒⠲⠤⠤⢤⣤⣄⣤⡤⠤⠤⠖⠒⠛⢧⢹⡏⠂⣀⣀⣀⣀⣀⡀⠘⣆⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⠀⢠⢏⠉⠀⠀⠀⠀⠀⢹⠀⠀⠀⠀⠀⠀
                                                                           ..   ..-==.
                                                                       .=#=..*@*%-. :@#.
             .-###%%#-                   :*#####****####:             .#%.   -@@.   .*-.
           .-@+    .*%                  .#*.   *@+.                  .+@*   .-@+
           :%%      -#                  .#.    *@+.                  .#@:   .+@-
           -%@-                                *@+.                  :%@.   .%@:
           .*@@%-..       .=@@@%-.             *@=...:*@%-    :@%...:=@@-----@@-:::.
             .+%@@%=:.  .*@:  .*@#.            *@=.    #@=    =@#   .=@@    .@@:
               ..:@@@+ .*@.    .*@-            #@=.    #@-   .#@#   .=@@    .@%:
                  .=@@.:%@.    .+@-            #@=.   .@%-  .=*@*   .=@%    .@#.
          .+-.     .#@.:%@.    :#%.            %@-    .@#.  :+*@#   .=@+    .@*.
          .*#.    .+@: .*@%.  .=%:             @@-    :@%-.=#.-@%.  .+@-    .@+.
          .=%%@%%%#-.    :%@%%%-.             .%#:     =%@%=. .+%%#-.+@:    :@=.
                                                                    .*#.    *#.
                                                                    :@=.   .@+.
                                                             .:.   .#+:.  .%+.
                                                             :%@#**#:-%@##*:
                                                              ......  ....
*/


/*
O struct special serve para guardar a mensagem de boas vindas, a mensagem de quando o user repete um input e a mensagem
de despedida.

Aqui o mais confuso de ler são as mensagens de despedida, o farewell_keywords são todas as palavras de despedida possíveis
que o user pode inserir (no .dat costuma ser 1 mas vai dar ao mesmo). O farewell_keywords_amount é a quantidade de palavras de despedida e o farewell
é a mensagem de despedida do bot
*/

typedef struct
{
    char* welcome;
    char* repeat;
    char** farewell_keywords;
    int farewell_keywords_amount;
    char* farewell;
} Special;

/*
Este struct serve para as keywords normais que serão usadas durante o chat. keywords é como se fossem as perguntas e
responses são as respostas do bot a essas perguntas.

O next_response serve para quando tens a mesma resposta para várias palavras chave, aqui esta variável é responsável para
escolher o índice de cada resposta a utilizar (estas serão escolhidas iteradamente)
*/
typedef struct
{
    char** keywords;
    char** responses;
    int keyword_amount;
    int response_amount;
    int next_response;
} ChatEntry;

/*
Este struct serve para o bot trocar verbos, ou seja ele vê se o input tem um dos verbos da primeira componente do vetor
e substitui pelo verbo na segunda componente
*/

typedef struct
{
    char in[20];
    char out[20];
} ConjugationRule;

/*
Regras de conjugação para inglês
*/
ConjugationRule conj_en[] = {
    {"ARE", "AM"}, {"AM", "ARE"}, {"WERE", "WAS"}, {"WAS", "WERE"},
    {"I", "YOU"}, {"YOUR", "MY"}, {"MY", "YOUR"}, {"IVE", "YOUVE"},
    {"YOUVE", "IVE"}, {"IM", "YOURE"}, {"ME", "YOU"}, {"US", "YOU"},
    {"WE", "YOU"}
};

/*
Regras de conjugação para inglês
*/
ConjugationRule conj_pt[] = {
    {"EU", "TU"}, {"TU", "EU"}, {"COMIGO", "CONTIGO"}, {"CONTIGO", "COMIGO"},
    {"TEU", "MEU"}, {"SEU", "MEU"}, {"TEUS", "MEUS"}, {"SEUS", "MEUS"},
    {"TUA", "MINHA"}, {"SUA", "MINHA"}, {"TUAS", "MINHAS"}, {"SUAS", "MINHAS"},
    {"MEU", "TEU"}, {"MEUS", "TEUS"}, {"MINHA", "TUA"}, {"MINHAS", "TUAS"},
    {"MIM", "TI"}, {"TI", "MIM"}
};

/*
isto só serve para tirar o número de elementos do vetor.
*/
int num_conj_en = sizeof(conj_en) / sizeof(conj_en[0]);
int num_conj_pt = sizeof(conj_pt) / sizeof(conj_pt[0]);

/*
Sim eu gosto de usar function prototypes porque fica mais bonito e fácil de ler ᕙ(⇀‸↼‶)ᕗ
*/
void* safe_malloc(size_t size);

void* safe_realloc(void* ptr, size_t size);

void format_line(char str[]);

void clean_input(char str[]);

void conjugate_text(char in[], char out[], int is_pt);

void substitute_asterisk(char base[], char conj[], char final[]);

ChatEntry* load_database(FILE* fp, Special* esp, int* total);

char* find_word(const char* string, const char* word);

char* my_strdup(const char* s);

void free_all(Special* esp, ChatEntry* base, int total);

void print_help(const char* prog_name);

char* custom_getline(char** lineptr, size_t* n, FILE* stream);

size_t max_conj_out_len(int is_pt);

static void close_files(FILE* fp_in, FILE* fp_out, FILE* fp_log);







int main(int argc, char* argv[])
{
    int i = 0;
    int k = 0;
    int opt;
    /* Valores por omissão - Falta de argumentos da linha de comando */
    char* db_filename = "eliza.dat";
    FILE* fp_in  = stdin;
    FILE* fp_out = stdout;
    FILE* fp_log = NULL;
    int is_pt = 0;

    /* Ler argumentos da linha de comando */
    while ((opt = getopt(argc, argv, "y:i:o:l:ph")) != -1)
    {
        switch (opt)
        {
        case 'y':
            db_filename = optarg;
            break;
        case 'i':
            fp_in = fopen(optarg, "r");
            if (fp_in == NULL)
            {
                fprintf(stderr, "Erro ao abrir ficheiro de entrada: %s\n", optarg);
                close_files(stdin, fp_out, fp_log);
                return EXIT_FAILURE;
            }
            break;
        case 'o':
            fp_out = fopen(optarg, "w");
            if (fp_out == NULL)
            {
                fprintf(stderr, "Erro ao abrir ficheiro de saida: %s\n", optarg);
                close_files(fp_in, stdout, fp_log);
                return EXIT_FAILURE;
            }
            break;
        case 'l':
            fp_log = fopen(optarg, "w");
            if (fp_log == NULL)
            {
                fprintf(stderr, "Erro ao abrir ficheiro de log: %s\n", optarg);
                close_files(fp_in, fp_out, NULL);
                return EXIT_FAILURE;
            }
            break;
        case 'p':
            is_pt = 1;
            break;
        case 'h':
            print_help(argv[0]);
            close_files(fp_in, fp_out, fp_log);
            return EXIT_SUCCESS;
        /* Da print nas instrucoes do help caso haja argumentos invalidos*/
        default:
            print_help(argv[0]);
            close_files(fp_in, fp_out, fp_log);
            return EXIT_FAILURE;
        }
    }

    FILE* fp = fopen(db_filename, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Erro ao abrir base de dados: %s\n", db_filename);
        close_files(fp_in, fp_out, fp_log);
        return EXIT_FAILURE;
    }

    /* Inicializar variaveis a zero para impedir comportamentos indefinidos*/
    Special esp = {0};
    int total = 0;

    char* input = NULL;
    size_t input_n = 0;

    char* last_input = NULL;

    ChatEntry* base = load_database(fp, &esp, &total);
    fclose(fp);

    /* Precomputar o maior tamanho possivel para a conjugacao */
    size_t max_out = max_conj_out_len(is_pt);

    if (esp.welcome != NULL)
    {
        fprintf(fp_out, "%s\n", esp.welcome);
        if (fp_log != NULL) fprintf(fp_log, "%s\n", esp.welcome);
    }

    while (custom_getline(&input, &input_n, fp_in) != NULL)
    {
        /* Salva o input "cru" para meter no log antes deste ser modificado pelo clean_input */
        char* raw = my_strdup(input);
        int rlen = strlen(raw);
        if (rlen > 0 && raw[rlen - 1] == '\n') raw[rlen - 1] = '\0';
        /* Remove as quebras de linha \r que o windows mete */
        rlen = strlen(raw);
        if (rlen > 0 && raw[rlen - 1] == '\r') raw[rlen - 1] = '\0';

        clean_input(input);

        /* Regista a entrada não processada no ficheiro do log (mesmo linhas vazias/com pontuação). */
        if (fp_log != NULL) fprintf(fp_log, "%s\n", raw);
        free(raw);

        if (strlen(input) == 0) continue;

        if ((!is_pt && strcmp(input, "BYE") == 0) ||
            (is_pt  && strcmp(input, "ADEUS") == 0))
        {
            if (esp.farewell != NULL)
            {
                fprintf(fp_out, "%s\n", esp.farewell);
                if (fp_log != NULL) fprintf(fp_log, "%s\n", esp.farewell);
            }
            break;
        }

        int farewell_input = 0;
        for (i = 0; i < esp.farewell_keywords_amount; i++)
        {
            if (find_word(input, esp.farewell_keywords[i]) != NULL)
            {
                farewell_input = 1;
                break;
            }
        }
        if (farewell_input)
        {
            if (esp.farewell != NULL)
            {
                fprintf(fp_out, "%s\n", esp.farewell);
                if (fp_log != NULL) fprintf(fp_log, "%s\n", esp.farewell);
            }
            break;
        }

        if (last_input != NULL && strcmp(input, last_input) == 0)
        {
            if (esp.repeat != NULL)
            {
                fprintf(fp_out, "%s\n", esp.repeat);
                if (fp_log != NULL) fprintf(fp_log, "%s\n", esp.repeat);
            }
            continue;
        }

        free(last_input);
        last_input = my_strdup(input);

        int found = 0;
        for (i = 0; i < total; i++)
        {
            for (k = 0; k < base[i].keyword_amount; k++)
            {
                char* match = find_word(input, base[i].keywords[k]);
                if (match != NULL)
                {
                    int r = base[i].next_response;
                    int len_key = strlen(base[i].keywords[k]);

                    /* o rest é basicamente tudo o que vem depois da keyword correspondente */
                    size_t rest_len = strlen(match + len_key) + 1;
                    char* rest = safe_malloc(rest_len);
                    strcpy(rest, match + len_key);

                    int p = 0;
                    while (rest[p] == ' ') p++;

                    /* Contar as palavras do rest para computar o maior tamanho possível para o resultado da conjugacao conj */
                    int word_count = 0;
                    size_t x;
                    for (x = 0; x < rest_len; x++)
                    {
                        if (rest[x] == ' ' || rest[x] == '\0') word_count++;
                    }

                    /* Forçar cada palavra a ter no máximo max_out caracteres + 1 para o espaço */
                    size_t conj_len = (size_t)word_count * (max_out + 1) + 1;
                    char* conj = safe_malloc(conj_len);
                    conj[0] = '\0';

                    size_t final_len = strlen(base[i].responses[r]) + conj_len + 2;
                    char* final = safe_malloc(final_len);

                    conjugate_text(&rest[p], conj, is_pt);
                    substitute_asterisk(base[i].responses[r], conj, final);

                    fprintf(fp_out, "%s\n", final);
                    if (fp_log != NULL) fprintf(fp_log, "%s\n", final);

                    base[i].next_response = (r + 1) % base[i].response_amount;
                    found = 1;

                    free(rest);
                    free(conj);
                    free(final);
                    break;
                }
            }
            if (found) break;
        }

        if (!found && total > 0)
        {
            int ult = total - 1;
            int r = base[ult].next_response;

            size_t final_len = strlen(base[ult].responses[r]) + 2;
            char* final = safe_malloc(final_len);

            substitute_asterisk(base[ult].responses[r], "", final);
            fprintf(fp_out, "%s\n", final);
            if (fp_log != NULL) fprintf(fp_log, "%s\n", final);

            base[ult].next_response = (r + 1) % base[ult].response_amount;
            free(final);
        }
    }

    free(input);
    free(last_input);

    free_all(&esp, base, total);
    close_files(fp_in, fp_out, fp_log);

    return EXIT_SUCCESS;
}


/* Nos comentários seguintes o meu caro colega Diogo só para ser diferente de mim gosta de os meter depois do codigo e não
 * antes por isso peço desculpa por qualquer inconsistência :p
 */


void print_help(const char* prog_name)
{
    printf("Uso: %s [OPTIONS]\n", prog_name);
    printf("Opcoes:\n");
    printf("  -h            Mostra esta ajuda e termina\n");
    printf("  -f filename   Ficheiro com base de dados de respostas (por omissao: eliza.dat)\n");
    printf("  -i filename   Ficheiro de entrada (por omissao: stdin)\n");
    printf("  -o filename   Ficheiro de saida (por omissao: stdout)\n");
    printf("  -l filename   Ficheiro de log do input e output\n");
    printf("  -p            Usar regras de portugues em vez de ingles\n");
}
/*
 * Exibe o manual de instruções/ajuda no terminal.
 * Quando o programa é executado com um comando inválido (failsafe) ou o utilizador usa o parametro "-h".
 */



char* custom_getline(char** lineptr, size_t* n, FILE* stream)
{
    size_t pos = 0;
    int c;

    if (*lineptr == NULL || *n == 0)
    {
        *n = 128;
        *lineptr = safe_malloc(*n);
    }

    while ((c = fgetc(stream)) != EOF)
    {
        if (pos + 2 > *n)
        {
            size_t new_size = *n * 2;
            *lineptr = safe_realloc(*lineptr, new_size);
            *n = new_size;
        }

        (*lineptr)[pos++] = (char)c;
        if (c == '\n') break;
    }

    if (pos == 0) return NULL;

    (*lineptr)[pos] = '\0';
    return *lineptr;
}
/*
 * Lê uma linha completa de uma linha completa de um ficheiro ou do input.
 * Realoca memória dinamicamente se a linha for maior que o buffer atual.
 * Retorna o ponteiro para a string lida ou NULL ao atingir o fim do ficheiro (EOF).
 * Supostamente isto é uma função que já existe mas não no C89/C90 por isso tivemos de improvisar
 */


void format_line(char str[])
{
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\r' || str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
        str[i] = toupper((unsigned char)str[i]);
    }
}
/*
 * Formata a linha removendo os newline characters (\n ou \r)
 * e também converte todos os caracteres para maiúsculas.
 */


void clean_input(char str[])
{
    int i, j = 0;
    int last_was_space = 0;

    for (i = 0; str[i] != '\0'; i++)
    {
        unsigned char c = (unsigned char)str[i];

        if (isalnum(c))
        {
            str[j++] = toupper(c);
            last_was_space = 0;
        }
        else if (isspace(c))
        {
            if (j > 0 && !last_was_space)
            {
                str[j++] = ' ';
                last_was_space = 1;
            }
        }
    }

    if (j > 0 && str[j - 1] == ' ') j--;

    str[j] = '\0';
}
/*
 * Normaliza a string: Converte para maiúsculas e remove caracteres não alfanuméricos
 * e colapsa múltiplos espaços em um só, elimina também todos os espaços vazios no final.
 */


size_t max_conj_out_len(int is_pt)
{
    size_t max_len = 1;
    int i;

    if (!is_pt)
    {
        for (i = 0; i < num_conj_en; i++)
        {
            size_t l = strlen(conj_en[i].out);
            if (l > max_len) max_len = l;
        }
    }
    else
    {
        for (i = 0; i < num_conj_pt; i++)
        {
            size_t l = strlen(conj_pt[i].out);
            if (l > max_len) max_len = l;
        }
    }

    return max_len;
}
/*
 * Calcula o comprimento máximo das strings de substituição (conjugações).
 * Percorre a lista do idioma selecionado (EN ou PT) para determinar o maior tamanho.
 * Devolve o tamanho da maior palavra encontrada (pelo menos 1).
 */


void conjugate_text(char in[], char out[], int is_pt)
{
    int i = 0;
    size_t len = strlen(in) + 1;
    char* temp = safe_malloc(len);
    strcpy(temp, in);
    out[0] = '\0';

    size_t max_out = max_conj_out_len(is_pt);

    char* token = strtok(temp, " ");
    char* next = NULL;
    while (token != NULL)
    {
        next = strtok(NULL, " ");

        size_t word_size = strlen(token) + 1;
        if (word_size < max_out + 1) word_size = max_out + 1;
        char* word = safe_malloc(word_size);

        int changed = 0;
        if (!is_pt)
        {
            if (strcmp(token, "YOU") == 0)
            {
                if (next == NULL) strcpy(word, "ME");
                else strcpy(word, "I");
                changed = 1;
            }
            else
            {
                for (i = 0; i < num_conj_en; i++)
                {
                    if (strcmp(token, conj_en[i].in) == 0)
                    {
                        strcpy(word, conj_en[i].out);
                        changed = 1;
                        break;
                    }
                }
            }
        }
        else
        {
            for (i = 0; i < num_conj_pt; i++)
            {
                if (strcmp(token, conj_pt[i].in) == 0)
                {
                    strcpy(word, conj_pt[i].out);
                    changed = 1;
                    break;
                }
            }
        }

        if (!changed) strcpy(word, token);
        strcat(out, word);
        if (next != NULL) strcat(out, " ");

        free(word);
        token = next;
    }
    free(temp);
}
/*
 * Ajusta a gramática da frase trocando os pronomes e verbos (conjugação).
 * Percorre as palavras do texto e substitui os termos conforme o idioma (EN ou PT).
 * Garante que a resposta da Eliza seja coerente com a pessoa que fala.
 */


void substitute_asterisk(char base[], char conj[], char final[])
{
    int i = 0;
    int pos = -1;
    final[0] = '\0';

    for (i = 0; base[i] != '\0'; i++)
    {
        if (base[i] == '*' || base[i]== '+')
        {
            pos = i;
            break;
        }
    }

    if (pos != -1)
    {
        for (i = 0; i < pos; i++)
        {
            final[i] = base[i];
        }
        final[pos] = '\0';

        if (pos > 0 && final[pos - 1] != ' ' && strlen(conj) > 0)
        {
            strcat(final, " ");
        }

        strcat(final, conj);

        size_t current_len = strlen(final);
        for (i = pos + 1; base[i] != '\0'; i++)
        {
            final[current_len++] = base[i];
        }
        final[current_len] = '\0';
    }
    else
    {
        strcpy(final, base);
    }
}
/*
 * Substitui o carácter '*' numa frase base pelo texto conjugado.
 * Reconstrói a frase final garantindo o espaçamento correto entre as palavras.
 * Se não existir um asterisco, copia a frase base sem alterações.
 */


ChatEntry* load_database(FILE* fp, Special* esp, int* total)
{
    int i = 0;

    char* buf = NULL;
    size_t buf_n = 0;

    esp->farewell_keywords_amount = 0;
    esp->farewell_keywords = NULL;
    esp->welcome = NULL;
    esp->repeat = NULL;
    esp->farewell = NULL;

    for (i = 0; i < 3; i++)
    {
        while (custom_getline(&buf, &buf_n, fp))
        {
            format_line(buf);
            if (strlen(buf) == 0) continue;
            if (strcmp(buf, "!") == 0) break;

            if (i == 2)
            {
                esp->farewell_keywords = safe_realloc(esp->farewell_keywords,(esp->farewell_keywords_amount + 1) * sizeof(char*));
                esp->farewell_keywords[esp->farewell_keywords_amount] = my_strdup(buf);
                esp->farewell_keywords_amount++;
            }
        }

        if (custom_getline(&buf, &buf_n, fp))
        {
            format_line(buf);
            if (i == 0) esp->welcome = my_strdup(buf);
            else if (i == 1) esp->repeat = my_strdup(buf);
            else if (i == 2) esp->farewell = my_strdup(buf);
        }

        while (custom_getline(&buf, &buf_n, fp))
        {
            format_line(buf);
            if (strcmp(buf, ".") == 0) break;
        }
    }

    int idx = 0;
    ChatEntry* base = NULL;
    int current_capacity = 0;

    while (custom_getline(&buf, &buf_n, fp))
    {
        format_line(buf);
        if (strlen(buf) == 0) continue;

        if (idx >= current_capacity)
        {
            current_capacity++;
            base = safe_realloc(base, current_capacity * sizeof(ChatEntry));
            base[idx].keywords = NULL;
            base[idx].responses = NULL;
            base[idx].keyword_amount = 0;
            base[idx].response_amount = 0;
            base[idx].next_response = 0;
        }

        if (strcmp(buf, "!") == 0)
        {
            while (custom_getline(&buf, &buf_n, fp))
            {
                format_line(buf);
                if (strcmp(buf, ".") == 0) break;

                if (strlen(buf) > 0)
                {
                    base[idx].responses = safe_realloc(base[idx].responses,
                                                       (base[idx].response_amount + 1) * sizeof(char*));
                    base[idx].responses[base[idx].response_amount] = my_strdup(buf);
                    base[idx].response_amount++;
                }
            }
            base[idx].next_response = 0;
            idx++;
        }
        else
        {
            base[idx].keywords = safe_realloc(base[idx].keywords,
                                              (base[idx].keyword_amount + 1) * sizeof(char*));
            base[idx].keywords[base[idx].keyword_amount] = my_strdup(buf);
            base[idx].keyword_amount++;
        }
    }

    /* Libertar entrada incompleta (keywords sem respostas) no fim do ficheiro */
    if (base != NULL && idx < current_capacity && base[idx].keyword_amount > 0)
    {
        int j;
        for (j = 0; j < base[idx].keyword_amount; j++)
            free(base[idx].keywords[j]);
        free(base[idx].keywords);
        base[idx].keywords = NULL;
    }

    free(buf);

    *total = idx;
    return base;
}
/*
 * Carrega a base de dados do ficheiro para as estruturas de memória.
 * Processa mensagens especiais (boas-vindas, despedida) e mapeia palavras-chave
 * para as suas respetivas respostas, gerindo a alocação dinâmica dos dados.
 * Retorna o array de entradas de chat e atualiza o total de regras lidas.
 */


char* find_word(const char* string, const char* word)
{
    int len = strlen(word);
    char* p = (char*)string;
    while ((p = strstr(p, word)) != NULL)
    {
        if ((p == string || !isalnum((unsigned char)p[-1])) && !isalnum((unsigned char)p[len]))
        {
            return p;
        }
        p++;
    }
    return NULL;
}
/*
 * Localiza a primeira ocorrência de uma palavra isolada numa string.
 * Verifica as extremidades do termo para garantir que não faz parte de outra palavra.
 * Retorna o ponteiro para a ocorrência encontrada ou NULL caso não exista.
 */


char* my_strdup(const char* s)
{
    char* d = safe_malloc(strlen(s) + 1);
    strcpy(d, s);
    return d;
}
/*
 * Duplica uma string na memória de forma segura.
 * Aloca dinamicamente o espaço necessário e copia o conteúdo original.
 * Retorna o ponteiro para a nova string independente.
 */


void free_all(Special* esp, ChatEntry* base, int total)
{
    int i, j;

    if (esp->welcome) free(esp->welcome);
    if (esp->repeat)  free(esp->repeat);
    if (esp->farewell) free(esp->farewell);
    for (i = 0; i < esp->farewell_keywords_amount; i++)
        free(esp->farewell_keywords[i]);
    if (esp->farewell_keywords) free(esp->farewell_keywords);

    for (i = 0; i < total; i++)
    {
        for (j = 0; j < base[i].keyword_amount; j++)
            free(base[i].keywords[j]);
        if (base[i].keywords) free(base[i].keywords);

        for (j = 0; j < base[i].response_amount; j++)
            free(base[i].responses[j]);
        if (base[i].responses) free(base[i].responses);
    }
    if (base) free(base);
}
/*
 * Valgrind, Liberta toda a memória dinâmica alocada no programa.
 * Percorre as estruturas especiais e a base de dados para apagar strings e arrays,
 * prevenindo fugas de memória (memory leaks) antes do encerramento.
 */


void* safe_malloc(size_t size)
{
    void* p = malloc(size);
    if (p == NULL)
    {
        fprintf(stderr, "Erro: memoria insuficiente\n");
        exit(EXIT_FAILURE);
    }
    return p;
}

void* safe_realloc(void* ptr, size_t size)
{
    void* p = realloc(ptr, size);
    if (p == NULL)
    {
        fprintf(stderr, "Erro: memoria insuficiente\n");
        exit(EXIT_FAILURE);
    }
    return p;
}
/*
 * Versões seguras das funções padrão de alocação de memória (malloc e realloc).
 * Interrompem o programa com uma mensagem de erro caso o sistema
 * não consiga disponibilizar o espaço solicitado.
*/


static void close_files(FILE* fp_in, FILE* fp_out, FILE* fp_log)
{
    if (fp_in  != stdin)  fclose(fp_in);
    if (fp_out != stdout) fclose(fp_out);
    if (fp_log != NULL)   fclose(fp_log);
}
/*
 * Fecha de forma segura os ficheiros abertos pelo programa.
 * Garante que apenas são fechados ficheiros diferentes de stdin e stdout,
 * evitando erros ao tentar fechar streams padrão.
 * Também verifica se o ficheiro de log foi aberto antes de o fechar.
 */


/* --------------------------------------------* FIM *------------------------------------------------- */

/* E assim acaba o projeto. Criado por Diogo Reis -ist1118802 e Henrique Carvalho -ist1117463; Projeto UC Programação
⠀⠀⣶⣶⣶⣶⣶⣶⣶⣶⣶⣾⣻⣿⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣶⣾⠉⠳⠂⢲
⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠁
⠀⠀⣿⣿⣿⣿⣿⣿⡿⣿⡽⣿⣿⣿⣿⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀
⠀⢰⣿⣿⣿⡿⢷⣤⣙⣿⣿⣿⣹⣿⣿⣿⣿⢿⣿⣯⣿⣿⣿⣿⣿⣿⢤⡎⠀⠀
⣴⣿⣟⠛⠋⣢⡤⣽⣿⣿⠯⠛⠟⠛⠏⠛⠣⡿⣿⡿⣿⣿⣿⣿⣿⣿⢺⠇⠀⠀
⣿⣿⣿⡩⠽⣻⢿⠛⠉⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣿⣾⣿⣿⣿⣿⠸⠀⠀⠀
⣿⣿⣿⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠉⠙⣿⣿⣿⣿⡆⣆⠀⠀
⣿⣿⠛⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠂⢕⣂⣤⢤⣄⠀⠈⣟⣿⣿⣿⣿⡄⠀
⢻⣿⡙⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⠟⠉⠁⠈⠛⢧⡠⢜⣿⣿⣿⣿⣧⠀
⢸⣿⢡⣀⡀⠀⠀⠀⠀⢀⠀⢀⣴⣿⠟⣁⠄⠂⣁⣄⠀⠀⢣⢈⢿⣿⣿⣿⡉⠀
⠀⢹⡟⠉⠛⠻⠿⣶⣄⡀⠉⢰⠞⢁⣨⠖⢿⠿⠉⠉⠁⠀⠀⢇⠘⣿⠝⣻⣇⠀
⠀⠀⣧⠀⣀⣤⣴⣴⣢⢼⠀⠀⠓⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⡏⢆⠃⣿⡀
⠀⠀⣿⠐⢏⠨⠋⠁⠀⡞⡆⠀⠱⡈⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⢾⡇⠤⢠⣿⠁
⣠⣀⣿⠀⠀⠀⠀⠀⠀⢰⡇⠀⠀⠱⣀⠀⠀⠀⠀⠀⠀⠀⢀⡆⠀⣿⣶⣿⠋⠀
⣿⣿⣿⣇⠀⠀⠀⠀⠀⢠⠀⠀⠀⠀⠀⢳⠀⠀⠀⠀⠀⢠⡟⠀⠀⣿⣿⣿⣶⡇
⣿⣿⣿⣿⣆⠀⠀⠀⠀⠰⣳⣴⠖⢉⠭⠊⠀⠀⠀⠀⠀⠈⠀⠀⠀⣿⣿⣿⣿⡇
⣿⣿⣿⣿⣿⣷⣦⡤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠄⠀⠀⠀⠀⢠⢻⡿⣿⣿⣷
⣿⣿⣿⣿⣿⣿⣿⣯⡢⡀⠀⢤⡐⢉⡉⠭⠤⠘⠁⡀⠀⠀⠀⢀⡞⠀⣷⡘⢿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⢯⠉⠁⠀⠀⠀⣀⠄⠄⠀⠀⠀⢀⡞⠀⠀⢸⣹⡘⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡗⠒⠒⠚⠉⠁⠀⠀⠀⠀⢠⠞⠀⠀⠀⠀⡏⡇⢩
⣿⣿⣿⣿⣿⣿⣿⣿⡿⡵⢁⢾⣄⠀⠀⠀⠀⠀⠀⠀⣰⠏⠀⠀⠀⠀⠀⠃⢠⠀
⣿⣿⣿⣿⣿⣿⢟⠟⡌⠘⢅⣾⢻⠢⢄⣀⣀⣀⡤⠞⠁⠀⠀⠀⠀⠀⠀⡄⠘⠀

We are SO tuff ᕙ( •̀ ᗜ •́ )ᕗ   - H
For real ദ്ദി >.<   - D

"MY JEALOSY - Super Slowed" - vivi baby, ovg!



Temos um segredo no final <3 :3 ⸜(｡˃ ᵕ ˂ )⸝♡♡♡
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡞⠋⠉⠳⡄⠀⠀⠀⠀⢠⠴⠒⠳⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢀⡶⢶⡀⠀⠀⠀⠀⠀⠀⠀⢠⠏⠀⠀⠀⠀⢹⡄⠀⠀⣰⠋⠀⠀⠀⠸⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⣀⡼⠀⠀⠛⠒⠒⡦⠀⠀⠀⠀⡟⠀⠀⠀⠀⠀⠀⣷⠀⢰⡏⠀⠀⠀⠀⠀⣹⠀⠀⠀⠀⠀⠀⠀⠀⠀
⣏⠁⠀⠀⠀⠀⠀⣼⠁⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⣹⠀⢸⠀⠀⠀⠀⠀⠀⢸⠁⠀⠀⠀⠀⠀⠀ ⠀
⠀⠉⡶⠀⠀⠀⠀⠈⡆⠀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⢽⠀⢸⠀⠀⠀⠀⠀⠀⣽⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⢷⡤⠞⠉⠉⠉⠁⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⢸⡆⢸⠀⠀⠀⠀⠀⢀⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣆⠀⠀⠀⠀⠀⠈⠛⠋⠀⠀⢀⠄⡀⣸⠃⡀⠠⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡤⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⠀⠀⠠⠀⠀⠀⠀⠘⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡞⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠲⢀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠁⠀⠜⡄⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⡟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠀⠀⠠⠳⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣧⣠⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠒⠀⠀⠀⠀⠀⣰⠀⠐⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣀⣤⣾⠁⠈⣧⠀⠰⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣄⠀⠀⠀⠀⡿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠐⡇⠀⠘⠁⠀⠘⠲⢤⡀⠀⠀⠀⢀⠀⠀⠀⠀⠀⠈⠉⠀⠀⠀⢠⠇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠙⢦⣄⠀⣠⠤⠤⠄⠙⡇⠀⠀⢨⠷⢶⡋⠀⠀⠀⠀⠀⢀⣴⠋⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣧⠀⢷⣀⡴⠂⢠⣇⡀⠀⠀⠀⠀⠀⠀⠀⣀⣀⣴⠟⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠳⠤⣤⣤⡴⠋⠀⠹⣽⣛⣛⣿⠋⠉⠉⢁⡴⢋⣳⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠳⣄⡀⠀⠀⠉⠁⠀⠀⠀⣠⡞⠓⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠹⡍⠓⠦⢤⠤⠴⠶⣺⠟⠀⠀⠀⠀⠀⠀⠀⢀⣀⡀⡰⢲⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠓⠒⠛⠲⠶⠚⠁⠀⠀⠀⠀⠀⠀⠀⠀⠘⣏⠉⠁⠈⠲⣤
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡆⣀⡀⠀⡞⠁
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠁⠈⠙⠁⠀



⠀⠀⠀⢸⣦⡀⠀⠀⠀⠀⢀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢸⣏⠻⣶⣤⡶⢾⡿⠁⠀⢠⣄⡀⢀⣴⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣀⣼⠷⠀⠀⠁⢀⣿⠃⠀⠀⢀⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠴⣾⣯⣅⣀⠀⠀⠀⠈⢻⣦⡀⠒⠻⠿⣿⡿⠿⠓⠂⠀⠀⢀⡇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠉⢻⡇⣤⣾⣿⣷⣿⣿⣤⠀⠀⣿⠁⠀⠀⠀⢀⣴⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠸⣿⡿⠏⠀⢀⠀⠀⠿⣶⣤⣤⣤⣄⣀⣴⣿⡿⢻⣿⡆⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠟⠁⠀⢀⣼⠀⠀⠀⠹⣿⣟⠿⠿⠿⡿⠋⠀⠘⣿⣇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢳⣶⣶⣿⣿⣇⣀⠀⠀⠙⣿⣆⠀⠀⠀⠀⠀⠀⠛⠿⣿⣦⣤⣀⠀⠀
⠀⠀⠀⠀⠀⠀⣹⣿⣿⣿⣿⠿⠋⠁⠀⣹⣿⠳⠀⠀⠀⠀⠀⠀⢀⣠⣽⣿⡿⠟⠃
⠀⠀⠀⠀⠀⢰⠿⠛⠻⢿⡇⠀⠀⠀⣰⣿⠏⠀⠀⢀⠀⠀⠀⣾⣿⠟⠋⠁⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠋⠀⠀⣰⣿⣿⣾⣿⠿⢿⣷⣀⢀⣿⡇⠁⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠋⠉⠁⠀⠀⠀⠀⠙⢿⣿⣿⠇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀




⠀⠀⠀⢸⣦⡀⠀⠀⠀⠀⢀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢸⣏⠻⣶⣤⡶⢾⡿⠁⠀⢠⣄⡀⢀⣴⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣀⣼⠷⠀⠀⠁⢀⣿⠃⠀⠀⢀⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠴⣾⣯⣅⣀⠀⠀⠀⠈⢻⣦⡀⠒⠻⠿⣿⡿⠿⠓⠂⠀⠀⢀⡇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠉⢻⡇⣤⣾⣿⣷⣿⣿⣤⠀⠀⣿⠁⠀⠀⠀⢀⣴⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠸⣿⡿⠏⠀⢀⠀⠀⠿⣶⣤⣤⣤⣄⣀⣴⣿⡿⢻⣿⡆⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠟⠁⠀⢀⣼⠀⠀⠀⠹⣿⣟⠿⠿⠿⡿⠋⠀⠘⣿⣇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢳⣶⣶⣿⣿⣇⣀⠀⠀⠙⣿⣆⠀⠀⠀⠀⠀⠀⠛⠿⣿⣦⣤⣀⠀⠀
⠀⠀⠀⠀⠀⠀⣹⣿⣿⣿⣿⠿⠋⠁⠀⣹⣿⠳⠀⠀⠀⠀⠀⠀⢀⣠⣽⣿⡿⠟⠃
⠀⠀⠀⠀⠀⢰⠿⠛⠻⢿⡇⠀⠀⠀⣰⣿⠏⠀⠀⢀⠀⠀⠀⣾⣿⠟⠋⠁⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠋⠀⠀⣰⣿⣿⣾⣿⠿⢿⣷⣀⢀⣿⡇⠁⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠋⠉⠁⠀⠀⠀⠀⠙⢿⣿⣿⠇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀

⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠿⢛⣛⣩⣭⣭⣭⣭⣙⣩⣭⣭⣭⣭⣙⣛⠻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⣋⣵⣶⣿⣿⣿⣿⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⣦⣙⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢋⣴⣿⣿⡟⡿⢻⣿⣿⡟⣿⠸⣿⡙⣿⣿⣇⢻⣿⣿⣿⣿⣿⣷⣍⡻⣷⣬⡻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢣⣶⢿⡿⢋⠍⢰⠃⣾⣿⣿⢡⣿⡆⢿⣧⠹⣿⣿⣆⢻⣿⣿⣿⣿⣿⣿⣿⣦⡹⣷⣌⠻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠏⣴⡿⡡⠋⡴⢣⠢⠃⣼⣿⣿⢃⣾⣿⡇⣌⠻⣷⡈⠻⢿⣦⡙⢿⣿⣿⣿⣿⣿⣿⣷⣌⢿⣷⡜⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢋⣼⡟⠁⠄⣨⠞⡁⢀⣾⣿⡿⢃⣾⣿⢏⣴⣿⣷⣮⣙⡂⠄⠨⢙⡂⠙⠻⢿⣿⣿⣿⣿⣿⣧⡙⢿⣆⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣸⣿⠃⣴⣶⣿⠖⣣⣾⣿⠟⣡⡾⠟⣫⣼⣿⣿⣿⣿⣿⣷⣶⣤⣼⣷⣶⣦⣬⣙⡻⢿⣿⣿⣿⣷⣜⠿⣎⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⢠⣿⣯⣼⡿⢟⣡⣾⠿⢛⣡⣤⣴⣶⣿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣬⡙⣿⣿⣿⣷⣶⣆⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⠃⣾⣿⣿⣦⣤⣤⢀⣶⣾⢛⡭⠐⠒⠒⠬⡛⢿⣿⣿⢸⣿⣿⡌⣿⣿⡿⢋⠅⠒⠐⠒⢬⡝⢿⣷⡘⣿⣿⣿⣿⣿⣷⡜⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⢃⣾⣿⡡⡏⠀⠐⠀⠂⠀⣈⣼⣿⡇⢾⣿⣿⡆⢿⣿⣧⣀⠀⠰⠠⠅⠀⢹⡎⣿⣷⡘⣿⣿⣿⣿⣿⡿⠷⠬⢙⢻⢿⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⡏⣼⣿⣿⣿⡿⠶⠶⠶⢞⣫⣼⣿⠟⣡⣭⣶⣦⣽⣌⠻⣿⣦⣙⡲⠶⠶⠶⢿⣿⣿⣿⣧⠸⣿⣿⣿⣿⣿⣦⣤⣭⡭⢀⣿⣿⣿⣿⣿
⣿⣿⡟⢻⣿⣿⣿⣿⡏⣸⣿⣿⣿⡿⢠⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢋⣴⡿⠓⠹⣿⡏⠙⠿⢷⣎⢻⡻⣿⣿⣿⣿⣿⣿⣿⣿⣿⡆⢻⣿⣿⣿⣿⣿⡟⢉⣒⡁⣼⣿⣿⣿⡿
⣿⣿⣷⠠⣉⡛⠿⢛⣠⣿⣿⣿⣿⡇⣿⣿⣿⣿⣿⣿⣿⡿⢋⣵⣿⣦⣛⣠⣴⣾⣿⣷⣶⣤⣛⣛⣼⣿⣦⣙⢿⣿⣿⣿⣿⣿⣿⣷⢸⣿⣿⣿⣿⣿⣿⣿⡿⢡⣿⣿⣿⡿⠞
⣿⠋⢛⠷⠍⠛⢻⣿⣿⣿⣿⣿⣿⢰⣿⣿⣿⣿⣿⡿⣫⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣍⢻⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⡿⣡⣾⣿⣿⣿⣿⡌
⣿⠀⠦⡻⢿⣿⣿⣿⣿⣿⣿⣿⣟⢸⣿⣿⣿⣿⢏⣴⣿⣿⣿⠿⠟⠛⣛⡛⠉⠉⣉⠉⠉⢛⣛⠛⡛⠿⠿⣿⣿⣿⣷⡹⣿⣿⣿⣿⢸⣿⣿⣿⣿⠟⣫⠴⠟⣻⣿⣿⣿⡿⠁
⣿⣆⠳⣦⣤⣽⣿⣿⣿⣿⣿⣿⣗⢸⣿⣿⣿⠇⣾⣿⡟⠋⠀⣬⢡⣶⣎⣰⣿⣿⣀⣾⣿⣷⣱⣶⡎⣥⡔⡂⢍⢿⣿⣷⢹⣿⣿⡟⢸⣿⣿⠿⣷⡶⠖⣫⣴⣿⡿⠏⠁⠀⠒
⣿⣿⠣⠜⠻⢿⣿⣿⣿⣿⣿⣿⣿⠸⣿⣿⡏⢸⣿⡏⢠⢸⢇⣿⢻⣿⣿⣿⣿⣿⡛⣿⣿⣿⢿⣿⠿⣿⣇⣿⢈⠂⢹⣿⡌⣿⣿⡇⣿⡿⠛⠦⠄⣀⣿⡿⠉⠁⠀⠀⠀⠀⠀
⣿⣿⣷⣬⡐⠻⢿⢿⣿⣿⣿⣿⣿⡆⢻⣿⣿⢸⣿⠀⢆⢆⠣⠍⠀⠀⠀⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⢒⣋⠟⡄⠈⣿⡇⣿⡿⢰⡿⢁⣶⣤⣍⠻⠁⠀⠀⠀⠀⣀⣠⣀⣀
⣿⣿⣿⣿⣷⣀⠨⢼⣿⣿⣿⣿⣿⣧⠸⣿⣿⢸⣿⠀⠘⠊⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠐⠁⠀⣿⢣⣿⠇⡼⢃⣼⣿⣿⣿⣦⡐⢶⣶⣴⣶⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣷⣶⣤⣭⣭⣄⠙⢿⣆⢻⣿⡌⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣯⣼⡿⢀⣴⣿⣿⣿⣿⡏⢿⣷⣄⡙⢾⣿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⢠⡆⢲⣬⡈⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⡇⣾⣿⣿⣿⣿⣿⣿⢸⣿⣿⣿⡄⢿⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⣿⣿⠟⣠⣾⣿⣷⠸⣿⡇⢻⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⣿⣿⢠⣿⣿⣿⣿⣿⣿⡏⣼⣿⣿⣿⡇⠸⣿⣿⣿⣿
⣿⣿⣿⣿⣿⣿⡿⠛⠰⣿⣿⣿⣿⣆⢹⣿⠸⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⡟⣸⣿⣿⣿⣿⣿⡟⣰⣿⣿⣿⡿⢁⣷⣤⡹⣿⣿
⣿⣿⣿⣿⡟⢉⣴⣾⣆⠹⣿⣿⣿⣿⣆⠻⡆⣿⣿⣿⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣿⣿⠇⣿⣿⣿⣿⡿⢋⣴⣿⣿⣿⠟⣠⣾⣿⣿⣷⡌⢿
⣿⣿⣿⠋⣴⣿⣿⣿⣿⣷⡈⠻⣿⣿⣿⣿⣧⢸⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⢰⣿⣿⣿⣿⣷⣿⣿⣿⡿⢃⣴⣿⣿⣿⣿⣿⣿⡌
⣿⣿⢃⣾⣿⣿⣿⣿⣿⣿⣿⣦⡈⠻⣿⣿⣿⡈⣿⣿⣧⢠⢤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⠆⣾⣿⡏⣸⣿⣿⣿⣿⣿⣿⡿⢋⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿
⣿⠇⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣌⠻⢿⡇⢿⣿⣿⠰⢿⡂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣿⠇⣿⣿⡇⣿⣿⣿⣿⣿⡿⢋⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣦⢸⣿⣿⡄⢿⣟⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣛⠻⢸⣿⣿⢁⣿⣿⣿⠟⣁⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡇⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡀⣿⣿⣇⠙⣫⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠿⡇⣸⣿⡟⢸⠿⢋⣥⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠇⣿⣿⣿⣿⣿⣆⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢻⣿⣿⡄⠿⣯⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡻⣿⢀⣿⣿⡏⣠⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠀⣿⣿⣿⣿⣿⣿⡀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⢸⣿⣿⣇⢰⣿⢗⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢴⣧⠙⢸⣿⣿⠃⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠰⣿⣿⣿⣿⣿⣿⣧⠸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡈⣿⣿⣿⣆⢣⣿⢃⡀⠀⠀⠀⠀⠀⠀⣀⢰⣧⠻⢡⣿⣿⣿⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠘⣿⣿⣿⣿⣿⣿⣿⡆⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢿⣿⣯⠻⣦⠉⢿⡇⣿⡷⣶⢲⣿⡞⣿⠺⠟⣠⢿⣿⣿⡇⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⠈⣿⣿⣿⣿⣿⣿⣿⣿⡄⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⠸⣿⣿⣷⡙⢷⣦⣔⣈⠉⠛⠩⠛⢁⣉⣴⡾⢋⣼⣿⣟⢀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡄⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⢿⣿⣿⣿⣿⣿⣿⣿⣿⡆⢻⣿⣿⣿⣷⣭⣛⠻⠿⠿⠿⠿⠿⢛⣫⣴⣿⣿⣿⠇⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
⡇⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠹⣿⣿⣿⣿⣿⣿⣿⣿⡌⠿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⢿⢿⣿⣿⣿⡿⠏⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿
*/

