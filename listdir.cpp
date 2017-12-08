#include <windows.h>
#include <stdio.h>
#pragma warning( disable : 4996)

static int count;



int main() {
    	wchar_t s[512];              	// текущая папка
    	GetCurrentDirectory(512, s);	// получить текущую папку
    	wprintf(L"Starting in: %s\n", s);

    	count = 0;   // обнулить счетчик файлов    
		HANDLE hFind;                   	// номер поиска
		WIN32_FIND_DATA res;				// результат поиска
		hFind = FindFirstFile(L"*",&res);
		
		do {
    		count++; // некоторые файлы не считаются??
    		wprintf(L"%s\n",res.cFileName);

    		// ...
    		// здесь будет обход в глубину
		} while (FindNextFile(hFind, &res) != 0);
		FindClose(hFind);

        //dfs();                     	// запустить обход в глубину
   	 
    	wprintf(L"File count = %d\n", count);
    	return 0;
}


/*void dfs() {
	HANDLE hFind;                   	// номер поиска
	WIN32_FIND_DATA res;            	// результат поиска

	CHAR dir[] = ".\\*";
	hFind = FindFirstFile(dir, &res);   // найти первый файл

	do {
    	count++; // некоторые файлы не считаются??
    	_tprintf(TEXT("file #%d is <%s>\n"), count, res.cFileName);

    	// ...
    	// здесь будет обход в глубину
	} while (FindNextFile(hFind, &res) != 0);
	FindClose(hFind);
}
*/
