#include <windows.h>
#include <stdio.h>
#pragma warning( disable : 4996)

static int count;



int main() {
    	wchar_t s[512];              	// ������� �����
    	GetCurrentDirectory(512, s);	// �������� ������� �����
    	wprintf(L"Starting in: %s\n", s);

    	count = 0;   // �������� ������� ������    
		HANDLE hFind;                   	// ����� ������
		WIN32_FIND_DATA res;				// ��������� ������
		hFind = FindFirstFile(L"*",&res);
		
		do {
    		count++; // ��������� ����� �� ���������??
    		wprintf(L"%s\n",res.cFileName);

    		// ...
    		// ����� ����� ����� � �������
		} while (FindNextFile(hFind, &res) != 0);
		FindClose(hFind);

        //dfs();                     	// ��������� ����� � �������
   	 
    	wprintf(L"File count = %d\n", count);
    	return 0;
}


/*void dfs() {
	HANDLE hFind;                   	// ����� ������
	WIN32_FIND_DATA res;            	// ��������� ������

	CHAR dir[] = ".\\*";
	hFind = FindFirstFile(dir, &res);   // ����� ������ ����

	do {
    	count++; // ��������� ����� �� ���������??
    	_tprintf(TEXT("file #%d is <%s>\n"), count, res.cFileName);

    	// ...
    	// ����� ����� ����� � �������
	} while (FindNextFile(hFind, &res) != 0);
	FindClose(hFind);
}
*/
