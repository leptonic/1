// ttDlg.cpp : implementation file
//

#include "stdafx.h"
#include "tt.h"
#include "ttDlg.h"
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTtDlg dialog

CTtDlg::CTtDlg(CWnd* pParent /*=NULL*/)
: CDialog(CTtDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTtDlg)
	// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTtDlg)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTtDlg, CDialog)
//{{AFX_MSG_MAP(CTtDlg)
ON_WM_PAINT()
ON_WM_QUERYDRAGICON()
ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton10)
	ON_BN_CLICKED(IDC_BUTTON14, OnButton14)
	ON_BN_CLICKED(IDC_BUTTON15, OnButton15)
	ON_BN_CLICKED(IDC_BUTTON16, OnButton16)
	ON_BN_CLICKED(IDC_BUTTON17, OnButton17)
	ON_BN_CLICKED(IDC_BUTTON18, OnButton18)
	ON_BN_CLICKED(IDC_BUTTON19, OnButton19)
	ON_BN_CLICKED(IDC_BUTTON20, OnButton20)
	ON_BN_CLICKED(IDC_BUTTON22, OnButton22)
	ON_BN_CLICKED(IDC_BUTTON23, OnButton23)
	ON_BN_CLICKED(IDC_BUTTON24, OnButton24)
	ON_BN_CLICKED(IDC_BUTTON25, OnButton25)
	ON_BN_CLICKED(IDC_BUTTON26, OnButton26)
	ON_BN_CLICKED(IDC_BUTTON27, OnButton27)
	ON_BN_CLICKED(IDC_BUTTON28, OnButton28)
	ON_BN_CLICKED(IDC_BUTTON29, OnButton29)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton11)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton12)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTtDlg message handlers

BOOL CTtDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTtDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		
		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);
		
		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;
		
		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTtDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
BOOL ExecDirect(char *ss1 )
{

	SECURITY_ATTRIBUTES sa;
	
	HANDLE hRead,hWrite;
	
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	
	sa.lpSecurityDescriptor = NULL;
	
	sa.bInheritHandle = TRUE;
	
	if (!CreatePipe(&hRead,&hWrite,&sa,0))
		
	{
		
		return FALSE;
		
	}
	
	char command[1024]; //长达1K的命令行,够用了吧
	
	//strcpy(ss1,"ls ");
	
	strcpy(command,"Cmd.exe /C  ");	

	strcat(command,ss1);
	
	STARTUPINFO si;
	
	PROCESS_INFORMATION pi;
	
	si.cb = sizeof(STARTUPINFO);
	
	GetStartupInfo(&si);
	
	si.hStdError = hWrite; //把创建进程的标准错误输出重定向到管道输入
	
	si.hStdOutput = hWrite; //把创建进程的标准输出重定向到管道输入
	
	si.wShowWindow = SW_HIDE;
	
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	
	//关键步骤,CreateProcess函数参数意义请查阅MSDN
	
	if (!CreateProcess(NULL, command,NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi))
		
	{
		
		CloseHandle(hWrite);
		
		CloseHandle(hRead);
		
		return FALSE;
		
	}
	
	CloseHandle(hWrite);
	
	char buffer[4096] = {0}; //用4K的空间来存储输出的内容,只要不是显示文件内容,一般情况下是够用了。
	
	DWORD bytesRead;
	
	while (true)
		
	{
		
		if (ReadFile(hRead,buffer,4095,&bytesRead,NULL) == NULL)
			
			break;
		
		//buffer中就是执行的结果,可以保存到文本,也可以直接输出
		
		AfxMessageBox(buffer); //这里是弹出对话框显示
		
	}
	
	CloseHandle(hRead);
	
	return TRUE;
	
}
BOOL ExecDosCmd(char *ss1 )
{
	
#define EXECDOSCMD "adb shell " //可以换成你的命令
#define EXECDOSCMD2 "ls " //可以换成你的命令

	SECURITY_ATTRIBUTES sa;
	
	HANDLE hRead,hWrite;
	
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	
	sa.lpSecurityDescriptor = NULL;
	
	sa.bInheritHandle = TRUE;
	
	if (!CreatePipe(&hRead,&hWrite,&sa,0))
		
	{
		
		return FALSE;
		
	}
	
	char command[1024]; //长达1K的命令行,够用了吧
	
	//strcpy(ss1,"ls ");
	
	strcpy(command,"Cmd.exe /C  ");
	
	strcat(command,EXECDOSCMD);
	strcat(command,ss1);
	
	STARTUPINFO si;
	
	PROCESS_INFORMATION pi;
	
	si.cb = sizeof(STARTUPINFO);
	
	GetStartupInfo(&si);
	
	si.hStdError = hWrite; //把创建进程的标准错误输出重定向到管道输入
	
	si.hStdOutput = hWrite; //把创建进程的标准输出重定向到管道输入
	
	si.wShowWindow = SW_HIDE;
	
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	
	//关键步骤,CreateProcess函数参数意义请查阅MSDN
	
	if (!CreateProcess(NULL, command,NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi))
		
	{
		
		CloseHandle(hWrite);
		
		CloseHandle(hRead);
		
		return FALSE;
		
	}
	
	CloseHandle(hWrite);
	
	char buffer[4096] = {0}; //用4K的空间来存储输出的内容,只要不是显示文件内容,一般情况下是够用了。
	
	DWORD bytesRead;
	
	while (true)
		
	{
		
		if (ReadFile(hRead,buffer,4095,&bytesRead,NULL) == NULL)
			
			break;
		
		//buffer中就是执行的结果,可以保存到文本,也可以直接输出
		
		AfxMessageBox(buffer); //这里是弹出对话框显示
		
	}
	
	CloseHandle(hRead);
	
	return TRUE;
	
}
BOOL Check_is_number(char input[16])//bug  0 isnot number
{
	if ( input[0] >= '0' && input[0] <= '9' )
     return 1;
	else
	{
		AfxMessageBox("请填写数字"); 
		return 0;
	}
}
BOOL Check_device( )
{
	
#define EXECDOSCMD "adb get-state " //可以换成你的命令


	SECURITY_ATTRIBUTES sa;
	
	HANDLE hRead,hWrite;
	
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	
	sa.lpSecurityDescriptor = NULL;
	
	sa.bInheritHandle = TRUE;
	
	if (!CreatePipe(&hRead,&hWrite,&sa,0))
		
	{
		
		return FALSE;
		
	}
	
	char command[1024]; //长达1K的命令行,够用了吧
	
	//strcpy(ss1,"ls ");
	
	strcpy(command,"Cmd.exe /C  ");
	
	strcat(command,EXECDOSCMD);
	
	
	STARTUPINFO si;
	
	PROCESS_INFORMATION pi;
	
	si.cb = sizeof(STARTUPINFO);
	
	GetStartupInfo(&si);
	
	si.hStdError = hWrite; //把创建进程的标准错误输出重定向到管道输入
	
	si.hStdOutput = hWrite; //把创建进程的标准输出重定向到管道输入
	
	si.wShowWindow = SW_HIDE;
	
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	
	//关键步骤,CreateProcess函数参数意义请查阅MSDN
	
	if (!CreateProcess(NULL, command,NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi))
		
	{
		
		CloseHandle(hWrite);
		
		CloseHandle(hRead);
		
		return FALSE;
		
	}
	
	CloseHandle(hWrite);
	
	char buffer[4096] = {0}; //用4K的空间来存储输出的内容,只要不是显示文件内容,一般情况下是够用了。
	
	DWORD bytesRead;
	
	while (true)
		
	{
		
		if (ReadFile(hRead,buffer,4095,&bytesRead,NULL) == NULL)
			
			break;
		
		//buffer中就是执行的结果,可以保存到文本,也可以直接输出
		if(*(buffer+0)=='u'&& *(buffer+1)=='n'&& *(buffer+2)=='k' && *(buffer+3)=='n'&&*(buffer+4)=='o')
		{
				AfxMessageBox("没有检测到Android设备！"); //这里是弹出对话框显示
				return FALSE;

		}
		else
		{
				return TRUE;
		AfxMessageBox("=通讯正常=");
		}
	}
	
	CloseHandle(hRead);
	
	return TRUE;
	
}
BOOL ExecDosCmd_f(char *ss1 )
{
	
#define EXECDOSCMD "adb shell " //可以换成你的命令
#define EXECDOSCMD2 "ls " //可以换成你的命令

	SECURITY_ATTRIBUTES sa;
	
	HANDLE hRead,hWrite;
	
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	
	sa.lpSecurityDescriptor = NULL;
	
	sa.bInheritHandle = TRUE;
	
	if (!CreatePipe(&hRead,&hWrite,&sa,0))
		
	{
		
		return FALSE;
		
	}
	
	char command[1024]; //长达1K的命令行,够用了吧
	
	//strcpy(ss1,"ls ");
	
	strcpy(command,"Cmd.exe /C  ");
	
	strcat(command,EXECDOSCMD);
	strcat(command,ss1);
	
	STARTUPINFO si;
	
	PROCESS_INFORMATION pi;
	
	si.cb = sizeof(STARTUPINFO);
	
	GetStartupInfo(&si);
	
	si.hStdError = hWrite; //把创建进程的标准错误输出重定向到管道输入
	
	si.hStdOutput = hWrite; //把创建进程的标准输出重定向到管道输入
	
	si.wShowWindow = SW_HIDE;
	
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	
	//关键步骤,CreateProcess函数参数意义请查阅MSDN
	
	if (!CreateProcess(NULL, command,NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi))
		
	{
		
		CloseHandle(hWrite);
		
		CloseHandle(hRead);
		
		return FALSE;
		
	}
	Sleep(500);
	CloseHandle(hWrite);
	
	char buffer[4096] = {0}; //用4K的空间来存储输出的内容,只要不是显示文件内容,一般情况下是够用了。
	
	DWORD bytesRead;
	
	while (true)
		
	{
		
		if (ReadFile(hRead,buffer,4095,&bytesRead,NULL) == NULL)
			
			break;
		
		//buffer中就是执行的结果,可以保存到文本,也可以直接输出
		
		AfxMessageBox(buffer); //这里是弹出对话框显示
		
	}
	
	CloseHandle(hRead);
	
	return TRUE;
	
}
void write_file(char *para)
{
char sz[64];
strcpy(sz,"echo \"");
strcat(sz,para);
strcat(sz," \" \> \/proc\/driver\/camsensor ");
strcat(sz,"\n");
DWORD dw;
HANDLE hFile=CreateFile("temp.txt",GENERIC_WRITE,0,NULL,CREATE_ALWAYS,0,NULL);
WriteFile(hFile,sz,strlen(sz)+1,&dw,NULL);
CloseHandle(hFile);
}
void write_file_bb(char *para)
{
char sz[64];

strcpy(sz,"cd sys/kernel/debug \n");
strcat(sz,"echo regw:");
strcat(sz,para);
strcat(sz," >mtkfb ");
strcat(sz,"\n");
DWORD dw;
HANDLE hFile=CreateFile("temp.txt",GENERIC_WRITE,0,NULL,CREATE_ALWAYS,0,NULL);
WriteFile(hFile,sz,strlen(sz)+1,&dw,NULL);
CloseHandle(hFile);
}
void write_file_cmd(char *para)
{
char sz[64];

strcpy(sz,para);
strcat(sz,"\n");

DWORD dw;
HANDLE hFile=CreateFile("temp.txt",GENERIC_WRITE,0,NULL,CREATE_ALWAYS,0,NULL);
WriteFile(hFile,sz,strlen(sz)+1,&dw,NULL);
CloseHandle(hFile);
}
void write_file_cmd_big(char *para)
{
char sz[512];

strcpy(sz,para);
strcat(sz,"\n");

DWORD dw;
HANDLE hFile=CreateFile("temp.txt",GENERIC_WRITE,0,NULL,CREATE_ALWAYS,0,NULL);
WriteFile(hFile,sz,strlen(sz)+1,&dw,NULL);
CloseHandle(hFile);
}
bool Read_Iteration(char *cmd1)
{
	if(cmd1[0])//fei kong
	{
		write_file(cmd1);
		return 1;
	}	
	else
		return 0;

}
void RI_Iteration2(char *cmd1)
{
	if(	Read_Iteration(cmd1))
	{	
		Sleep(50);
		system("type temp.txt >> cmd.txt");
		system("del  temp.txt");
	}

}
bool Write_Iteration(char *cmd1, char *cmd2)
{
	if((cmd1[0])&&(cmd2[0]))//fei kong
	{
		strcat(cmd1," ");
		strcat(cmd1,cmd2);
		write_file(cmd1);
		return 1;
	}	
	else
		return 0;

}

void WI_Iteration2(char *cmd1, char *cmd2)
{
	if(	Write_Iteration(cmd1,cmd2))
	{	
		Sleep(50);
		system("type temp.txt >> cmd.txt");
		system("del  temp.txt");
	}

}
void CTtDlg::OnButton1() // Download para
{


	char cmd1 [32],cmd2[8];	
if(!Check_device())
return;
	system("del  cmd.txt");
	Sleep(50);


	GetDlgItemText(IDC_EDIT1,cmd1,8);
	GetDlgItemText(IDC_EDIT2,cmd2,8);
	if(	Write_Iteration(cmd1,cmd2))
	{
		system("copy temp.txt  cmd.txt");
		system("del  temp.txt");
	}

	memset(cmd1,0,sizeof(cmd1));
	memset(cmd2,0,sizeof(cmd2));
	GetDlgItemText(IDC_EDIT3,cmd1,8);
	GetDlgItemText(IDC_EDIT4,cmd2,8);
	WI_Iteration2(cmd1,cmd2);

	memset(cmd1,0,sizeof(cmd1));
	memset(cmd2,0,sizeof(cmd2));
	GetDlgItemText(IDC_EDIT5,cmd1,8);
	GetDlgItemText(IDC_EDIT6,cmd2,8);
	WI_Iteration2(cmd1,cmd2);
	memset(cmd1,0,sizeof(cmd1));
	memset(cmd2,0,sizeof(cmd2));
	GetDlgItemText(IDC_EDIT7,cmd1,8);
	GetDlgItemText(IDC_EDIT8,cmd2,8);
	WI_Iteration2(cmd1,cmd2);
	memset(cmd1,0,sizeof(cmd1));
	memset(cmd2,0,sizeof(cmd2));
	GetDlgItemText(IDC_EDIT9,cmd1,8);
	GetDlgItemText(IDC_EDIT10,cmd2,8);
	WI_Iteration2(cmd1,cmd2);
	memset(cmd1,0,sizeof(cmd1));
	memset(cmd2,0,sizeof(cmd2));
	GetDlgItemText(IDC_EDIT11,cmd1,8);
	GetDlgItemText(IDC_EDIT12,cmd2,8);
	WI_Iteration2(cmd1,cmd2);
	memset(cmd1,0,sizeof(cmd1));
	memset(cmd2,0,sizeof(cmd2));
	GetDlgItemText(IDC_EDIT13,cmd1,8);
	GetDlgItemText(IDC_EDIT14,cmd2,8);
	WI_Iteration2(cmd1,cmd2);
	memset(cmd1,0,sizeof(cmd1));
	memset(cmd2,0,sizeof(cmd2));
	GetDlgItemText(IDC_EDIT15,cmd1,8);
	GetDlgItemText(IDC_EDIT16,cmd2,8);
	WI_Iteration2(cmd1,cmd2);
	Sleep(50);
	system("adb shell < cmd.txt");
	Sleep(200);

} 	
void beepl()
{
   unsigned FREQUENCY[] = {792};  

 

    unsigned DELAY[] = {100};  

    int i;  

    for (i = 0; i < 25; i++)  

    {  

              Beep(FREQUENCY[i], DELAY[i]);  

    }  
}

void CTtDlg::OnButton2() //open log
{
	
	char cmd1[256];	
if(!Check_device())
return;	
	strcpy(cmd1,"am broadcast -a com.mediatek.mtklogger.ADB_CMD -e cmd_name start --ei cmd_target 1");
	ExecDosCmd(cmd1);

	
}

void CTtDlg::OnButton3() //install fps
{
	char cmd1[256];	
if(!Check_device())
return;
system("adb install Fps2D_3.1.0.apk");
Sleep(1000);
strcpy(cmd1,"am start -n com.edburnette.fps2d/com.edburnette.fps2d.Fps2D");
ExecDosCmd(cmd1);	
}

void CTtDlg::OnButton4() //clear log
{
system("adb shell rm -r sdcard/mtklog");
	
}

void CTtDlg::OnButton5() //read sensor
{


	char cmd1 [32];
if(!Check_device())
return;
	system("adb_log_out.bat"); //log out
	Sleep(1000);
	system("del  cmd.txt");
	Sleep(50);


	GetDlgItemText(IDC_EDIT1,cmd1,8);

	if(	Read_Iteration(cmd1))
	{
		system("copy temp.txt  cmd.txt");
		system("del  temp.txt");
	}

	memset(cmd1,0,sizeof(cmd1));
	GetDlgItemText(IDC_EDIT3,cmd1,8);
	RI_Iteration2(cmd1);

	memset(cmd1,0,sizeof(cmd1));
	GetDlgItemText(IDC_EDIT5,cmd1,8);
	RI_Iteration2(cmd1);

	memset(cmd1,0,sizeof(cmd1));
	GetDlgItemText(IDC_EDIT7,cmd1,8);
	RI_Iteration2(cmd1);

	memset(cmd1,0,sizeof(cmd1));
	GetDlgItemText(IDC_EDIT9,cmd1,8);
	RI_Iteration2(cmd1);

	memset(cmd1,0,sizeof(cmd1));
	GetDlgItemText(IDC_EDIT11,cmd1,8);
	RI_Iteration2(cmd1);

	memset(cmd1,0,sizeof(cmd1));
	GetDlgItemText(IDC_EDIT13,cmd1,8);
	RI_Iteration2(cmd1);

	memset(cmd1,0,sizeof(cmd1));
	GetDlgItemText(IDC_EDIT15,cmd1,8);
	RI_Iteration2(cmd1);



	Sleep(50);

	system("adb shell < cmd.txt");


	Sleep(200);
	
}

void CTtDlg::OnButton6() //make modem dead
{
	 
	char cmd1[256];		
if(!Check_device())
return;
	strcpy(cmd1,"am broadcast -a com.mediatek.mtklogger.ADB_CMD -e cmd_name force_modem_assert --ei cmd_target 2");
	ExecDosCmd(cmd1);	
}

void CTtDlg::OnButton7() 
{
	char cmd1[256];	
if(!Check_device())
return;
	strcpy(cmd1,"am broadcast -a com.mediatek.mtklogger.ADB_CMD -e cmd_name start --ei cmd_target 4");
	ExecDosCmd(cmd1);
	
}

void CTtDlg::OnButton8() 
{
	char cmd1[256];	
if(!Check_device())
return;
	strcpy(cmd1,"am broadcast -a com.mediatek.mtklogger.ADB_CMD -e cmd_name start --ei cmd_target 2");
	ExecDosCmd(cmd1);	
}

void CTtDlg::OnButton9() //check
{

	char cmd1[256];	
if(!Check_device())
return;
	strcpy(cmd1,"getprop debug.MB.running");
	ExecDosCmd(cmd1);
	Sleep(3000);
	
		
	strcpy(cmd1,"getprop debug.mdlogger.Running");
	ExecDosCmd(cmd1);
	Sleep(3000);

	
	strcpy(cmd1,"getprop persist.radio.netlog.Running");
	ExecDosCmd(cmd1);
	Sleep(3000);
}

void CTtDlg::OnButton10() 
{
	char cmd1[256];	
if(!Check_device())
return;
	strcpy(cmd1,"cat /sys/devices/virtual/misc/mtgpio/pin");
	ExecDosCmd(cmd1);
	
}

void CTtDlg::OnButton14() 
{
	char cmd1[256];	
if(!Check_device())
return;
	strcpy(cmd1,"df");
	ExecDosCmd(cmd1);
	
}

void CTtDlg::OnButton15() //process display
{
	// TODO: Add your control notification handler code here
	char cmd1[256];	
if(!Check_device())
return;
	//strcpy(cmd1,"top -n 1");//too many
	strcpy(cmd1,"ps");
	ExecDosCmd(cmd1);
}



bool read_process_ID( char *re)
{
	CFile file("killnamepid.txt",CFile::modeRead);
	char *pBuf,*ptr,*prt2,c;
	char prBuf[6];
	int iLen=file.GetLength();
	int i,iNum_end,i_chk;
	pBuf =new char[iLen+1];
	file.Read(pBuf,iLen);
	pBuf[iLen]=0;
	i_chk=0;
	c='\"';
	ptr=strrchr(pBuf, c);
//check 不知道为什么getline总是不能用。。
	for(i=0;i<iLen;i++)
	{
		   if ( *(ptr+i)=='\r' )
		 {
			i_chk++;
		 }
	}
//if (i_chk<5)
//return 0;
if (i_chk<4)
return 0;
//check over


	for(i=0;i<61;i++)
	{
		 if ( *(ptr+i) >= '0' && *(ptr+i) <= '9' )
		 {
			prt2=(ptr+i);
			break;
		 }
	}

	for(i=0;i<10;i++)
	{
		 if (!( *(prt2+i) >= '0' && *(prt2+i) <= '9' ))
		 {
			iNum_end=i;
			break;
		 }
	}

    memset(prBuf,0,10);
	memcpy(prBuf,prt2,iNum_end);
	c='\"';
	memcpy(re,prBuf,iNum_end);

//	AfxMessageBox(prBuf);
	file.Close();
	
return 1;
}
void CTtDlg::OnButton16() //kill process
{
	// TODO: Add your control notification handler code here
	char cmd1[64],name[16],cmd2[32];
	char *id= (char*) malloc(16);
if(!Check_device())
return;	
    memset(id,0,16);
	system("bz.bat");
	//AfxMessageBox("正在安装Busybox..."); 
	beepl();
	GetDlgItemText(IDC_EDIT22,name,16);
	strcpy(cmd1,"top -n 1 \| busybox grep \"");
	strcat(cmd1,name);
	strcat (cmd1,"\"\;exit");
	write_file_cmd(cmd1);
		Sleep(700);
	

	system("copy temp.txt cmd.txt");
	system("del temp.txt");	
	system("adb shell < cmd.txt >killnamepid.txt");



if(read_process_ID(id))
{
strcpy(cmd2,"adb shell kill ");
strcat(cmd2,id);
AfxMessageBox("干掉它！"); 
system(cmd2);
}
else
AfxMessageBox("没找到相关进程");
 
}

void CTtDlg::OnButton17() 
{
if(!Check_device())
return;
system("adb shell /system/bin/screencap -p /sdcard/screenshot.png"); 
Sleep(1000);
system("adb pull /sdcard/screenshot.png screenshot.png");
beepl();
Sleep(300);
system("mspaint screenshot.png");

}

void CTtDlg::OnButton18() 
{
	// TODO: Add your control notification handler code here
	Check_device();
}

void CTtDlg::OnButton19() 
{
if(!Check_device())
return;
system("ckl.bat");	
}

void CTtDlg::OnButton20() //write reg for bb
{
	char cmd1 [32],cmd2[32];	
if(!Check_device())
return;
	system("del  cmd.txt");
	Sleep(50);


	GetDlgItemText(IDC_EDIT23,cmd1,16);
	GetDlgItemText(IDC_EDIT24,cmd2,16);

	if((cmd1[0])&&(cmd2[0]))//fei kong
	{
		strcat(cmd1,"=");
		strcat(cmd1,cmd2);
		write_file_bb(cmd1);
	

		system("copy temp.txt  cmd.txt");
		system("del  temp.txt");
	
system("adb shell <  cmd.txt");
	}	
else
{
AfxMessageBox("请填入完整参数");
}
	
}

void CTtDlg::OnButton22() 
{
	
	char cmd1[256];	
if(!Check_device())
return;


	//strcpy(cmd1,"top -n 1");//too many
	system("adb shell service call phone 2 s16 \"112\"");
Sleep(200);

	system("adb shell input keyevent 66 ");
	
}

void CTtDlg::OnButton23() 
{
	if(!Check_device())
return;

	system("adb shell am start -a android.intent.action.SENDTO -d sms: 10086 --es sms_body \"hello\" --ez exit_on_sent true");
}

void CTtDlg::OnButton24() 
{
	CString ss;
	char cmd1[256],name[256];	

       char szFilter[]="Apk files(*.apk)|*.apk";

       CFileDialog dlg(1,NULL,NULL,NULL,szFilter);

       if(dlg.DoModal()==IDOK)
       {

          ss = dlg.GetPathName();
		  		   //AfxMessageBox(ss);
        }
	if(!Check_device())
	return;
	char *pStr =  (LPSTR)(LPCTSTR)ss;
	strcpy(name, pStr);
	strcpy(cmd1,"adb install ");
	strcat (cmd1,name);

AfxMessageBox(cmd1);
	ExecDirect(cmd1);
      
}

void CTtDlg::OnButton25() //all openFF
{
	char cmd1[512];
	if(!Check_device())
return;
	strcpy (cmd1,"echo performance > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor \n");
	strcat (cmd1,"echo performance > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor \n");
	strcat (cmd1,"echo 1 > /sys/devices/system/cpu/cpu1/online \n");
	strcat (cmd1,"echo performance > /sys/devices/system/cpu/cpu1/cpufreq/scaling_governor \n");
	strcat (cmd1,"echo 0 > /proc/mtk_hotplug/enable\n");
	write_file_cmd_big(cmd1);
	Sleep(700);
	system("copy temp.txt cmd.txt");
	system("del temp.txt");	
	system("adb shell < cmd.txt");
 


	
}

void CTtDlg::OnButton26() 
{
	char cmd1[512];
	if(!Check_device())
return;
	strcpy (cmd1,"echo ondemand > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor \n");
	strcat (cmd1,"echo 0 > /sys/devices/system/cpu/cpu1/online \n");
	strcat (cmd1,"echo 0 > /proc/mtk_hotplug/enable \n");	
	write_file_cmd_big(cmd1);
	Sleep(700);
	system("copy temp.txt cmd.txt");
	system("del temp.txt");	
	system("adb shell < cmd.txt");
	
}

void CTtDlg::OnButton27() 
{
	if(!Check_device())
return;
	system("layerdumper.bat");	
}

void CTtDlg::OnButton28() //write gpio 
{
char state[16];
char f1[16];
char f2[16];
char chk[13];
char cmd[32];
CButton*   pullsel=(CButton*)GetDlgItem(IDC_CHECK6);
CButton*   din=(CButton*)GetDlgItem(IDC_CHECK1);
CButton*   dout=(CButton*)GetDlgItem(IDC_CHECK2);
CButton*   pullen=(CButton*)GetDlgItem(IDC_CHECK3);
CButton*   dir=(CButton*)GetDlgItem(IDC_CHECK4);
CButton*   dinv=(CButton*)GetDlgItem(IDC_CHECK5);


	GetDlgItemText(IDC_EDIT17,f1,16);
//	GetDlgItemText(IDC_EDIT18,f2,16);

//if(!Check_device())return;
if (!(Check_is_number(f1)&&Check_is_number(f2)))return;

strcpy (state,f1);
strcat (state,"\:");
strcat (state,f2);
strcat (state," ");
 if(pullsel-> GetCheck()) 
chk[0]='1';
 else 
chk[0]='0';

 chk[1]= ' '; 
 if(din-> GetCheck()) 
chk[2]='1';
 else 
chk[2]='0';

  chk[3]= ' '; 
 if(dout-> GetCheck()) 
chk[4]='1';
 else 
chk[4]='0';

  chk[5]= ' '; 
 if(pullen-> GetCheck()) 
chk[6]='1';
 else 
chk[6]='0';

  chk[7]= ' '; 
 if(dir-> GetCheck()) 
chk[8]='1';
 else 
chk[8]='0';

  chk[9]= ' '; 
 if(dinv-> GetCheck()) 
chk[10]='1';
 else 
chk[10]='0';
 chk[11]= ' '; 
chk[12]=NULL;
strcat(state,chk);

strcpy(cmd,"adb shell echo \-w\=");
strcat(cmd,state);
strcat(cmd," \> \/sys\/devices\/virtual\/misc\/mtgpio\/pin");
AfxMessageBox(cmd);
//AfxMessageBox("check is %c,%c,%c,%c,%c,%c,",chk[0],chk[1],chk[2],chk[3],chk[4],chk[5]);
//	system(cmd);
}

void CTtDlg::OnButton29() 
{
	if(!Check_device())
return;
system("adb shell <setblmax.txt");	
}

void CTtDlg::OnButton11() 
{
	char vol[16];
	char add[16];
	int bank[2];
	char cmd[64]; 
	/*


 Example : write 0x5a to 0x17 of bank0 ? 

                 echo 17 5a > pmic_access_bank0 

                 cat pmic_access_bank0 	
	*/
GetDlgItemText(IDC_EDIT19,vol,16);
GetDlgItemText(IDC_EDIT20,add,16);
CButton*   radio=(CButton*)GetDlgItem(IDC_RADIO1);
CButton*   radio1=(CButton*)GetDlgItem(IDC_RADIO2);
 if(radio-> GetCheck()) 
bank[0]=1;
 else 
bank[0]=0;
 if(radio1-> GetCheck()) 
bank[1]=1;
 else 
bank[1]=0;

 if(!(bank[0]||bank[1])) {AfxMessageBox("Bank0 Bank1 您总要选一个吧");return;}

 strcpy(cmd,"echo ");
strcat(cmd,vol);
strcat(cmd," ");
strcat(cmd,add);
strcat(cmd," ");
strcat(cmd,">");
strcat(cmd," ");
	if(bank[0])
	{
		strcat(cmd,"pmic_access_bank0 \n");
		strcat(cmd,"cat pmic_access_bank0\n");
	}
	else
	{
		strcat(cmd,"pmic_access_bank1 \n");
		strcat(cmd,"cat pmic_access_bank1\n");
	}
	write_file_cmd_big(cmd);
	Sleep(700);
	system("copy temp.txt cmd.txt");
	system("del temp.txt");	
	system("adb shell < cmd.txt");

}

void CTtDlg::OnButton12() 
{
	/*
	 Example : read 0x17 of bank0 

                 echo 17 > pmic_access_bank0 

                 cat pmic_access_bank0 
	*/
	char vol[16];
	char add[16];
	int bank[2];
	char cmd[64]; 


GetDlgItemText(IDC_EDIT20,add,16);
CButton*   radio=(CButton*)GetDlgItem(IDC_RADIO1);
CButton*   radio1=(CButton*)GetDlgItem(IDC_RADIO2);
 if(radio-> GetCheck()) 
bank[0]=1;
 else 
bank[0]=0;
 if(radio1-> GetCheck()) 
bank[1]=1;
 else 
bank[1]=0;

 if(!(bank[0]||bank[1])) {AfxMessageBox("Bank0 Bank1 您总要选一个吧");return;}

 strcpy(cmd,"echo ");
strcat(cmd,add);
strcat(cmd," ");
strcat(cmd,">");
strcat(cmd," ");
	if(bank[0])
	{
		strcat(cmd,"pmic_access_bank0 \n");
		strcat(cmd,"cat pmic_access_bank0\n");
	}
	else
	{
		strcat(cmd,"pmic_access_bank1 \n");
		strcat(cmd,"cat pmic_access_bank1\n");
	}
	write_file_cmd_big(cmd);
	Sleep(700);
	system("copy temp.txt cmd.txt");
	system("del temp.txt");	
	system("adb shell < cmd.txt");


}
