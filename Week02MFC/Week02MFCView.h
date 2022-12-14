
// Week02MFCView.h: CWeek02MFCView 클래스의 인터페이스
//

#pragma once


class CWeek02MFCView : public CView
{
protected:
	BOOL Pressed = FALSE;

protected: // serialization에서만 만들어집니다.
	CWeek02MFCView() noexcept;
	DECLARE_DYNCREATE(CWeek02MFCView)

// 특성입니다.
public:
	CWeek02MFCDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CWeek02MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // Week02MFCView.cpp의 디버그 버전
inline CWeek02MFCDoc* CWeek02MFCView::GetDocument() const
   { return reinterpret_cast<CWeek02MFCDoc*>(m_pDocument); }
#endif
