
// Week02MFCView.cpp: CWeek02MFCView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Week02MFC.h"
#endif

#include "Week02MFCDoc.h"
#include "Week02MFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWeek02MFCView

IMPLEMENT_DYNCREATE(CWeek02MFCView, CView)

BEGIN_MESSAGE_MAP(CWeek02MFCView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CWeek02MFCView 생성/소멸

CWeek02MFCView::CWeek02MFCView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CWeek02MFCView::~CWeek02MFCView()
{
}

BOOL CWeek02MFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CWeek02MFCView 그리기

void CWeek02MFCView::OnDraw(CDC* pDC)
{
	CWeek02MFCDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CPen pen(PS_DASH, 1, RGB(255, 0, 0));

	int olddc = pDC->SaveDC();

	pDC->SelectObject(&pen);
	pDC->Ellipse(100, 100, 500, 500);
	pDC->TextOutW(10, 10, L"안녕하세요");
	//pDC->TextOutW(10, 10, _T("안녕하세요"));
	//pDC->TextOutW(10, 10, _TEXT("안녕하세요"));

	pDC->RestoreDC(olddc);
}

// CWeek02MFCView 인쇄

BOOL CWeek02MFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CWeek02MFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CWeek02MFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CWeek02MFCView 진단

#ifdef _DEBUG
void CWeek02MFCView::AssertValid() const
{
	CView::AssertValid();
}

void CWeek02MFCView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWeek02MFCDoc* CWeek02MFCView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWeek02MFCDoc)));
	return (CWeek02MFCDoc*)m_pDocument;
}
#endif //_DEBUG


// CWeek02MFCView 메시지 처리기

void CWeek02MFCView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	dc.Rectangle(point.x - 100, point.y - 100, point.x + 100, point.y + 100);

	CView::OnLButtonDblClk(nFlags, point);
}

void CWeek02MFCView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	Pressed = TRUE;

	CClientDC dc(this);
	dc.Ellipse(point.x - 50, point.y - 50, point.x + 50, point.y + 50);

	CView::OnLButtonDown(nFlags, point);
}


void CWeek02MFCView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	Pressed = FALSE;

	CClientDC dc(this);
	dc.Rectangle(point.x - 50, point.y - 50, point.x + 50, point.y + 50);
	CView::OnLButtonUp(nFlags, point);
}

void CWeek02MFCView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (Pressed == FALSE)
		return;

	CClientDC dc(this);
	dc.Ellipse(point.x - 50, point.y - 50, point.x + 50, point.y + 50);

	CView::OnMouseMove(nFlags, point);
}