
// CodMakeDlg.h : ͷ�ļ�
//

#include "afxwin.h"
#include <vector>
#include <map>

using namespace std;
#define MAX_ESIZE 256
#define CALL_LEVEL 2    //����CALL�Ĳ���
// CCodMakeDlg �Ի���
class CCodMakeDlg : public CDialog
{
// ����
public:
	CCodMakeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CODMAKE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDropFiles(HDROP hDropInfo);
	CListBox m_output;
	CStatic m_libname;

	void MakeCode(LPWSTR lpFile);

	void DebugMessage(char *format, ...);


	BOOL GenerateRelocationMap(unsigned char* pdll, ptrdiff_t delta);
	BOOL GenerateIATMap(unsigned char* pdll);

	INT Findprocend(ULONG FuncStartAddr,string& FuncText); //׷˷��������,����ÿ��������Ӧ���ı���ʽ

	
	
	map<ULONG, BOOL> m_relocation;
	map<ULONG, string> m_import;


	UINT CallLevel=0;



	map<ULONG, BOOL> m_block;

	map<string, string> m_FuncOk;  //���溯��,keyΪ��������,valueΪ�����ı�
	map<string, BOOL> m_call;   //keyΪcall�ĵ�ַ����,valueΪcall�����Ƿ��Ѿ����

	HANDLE	hFile;
	HMODULE	hLib;
	DWORD	dwWritten = 0;

	DWORD	SectionSize = 0;

	INT IsRelocated(ULONG addr,int len);
	CButton m_checksource;
};
