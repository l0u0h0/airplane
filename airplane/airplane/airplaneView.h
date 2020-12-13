
// airplaneView.h: CairplaneView 클래스의 인터페이스
//

#pragma once


class CairplaneView : public CView
{
protected: // serialization에서만 만들어집니다.
	CairplaneView() noexcept;
	DECLARE_DYNCREATE(CairplaneView)

// 특성입니다.
public:
	CairplaneDoc* GetDocument() const;

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
	virtual ~CairplaneView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	int back_x;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int type;
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	int index;
	int plane_y;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	int WinBottom;
	int WinRight;
	int map_idx;
	int text_y;
	int bird_index;
	int bird_x;
	int bird_y;
	int crashTest(int bird_x, int bird_y, int plane_y);
	void Restart();
	int bird_fly;
	int bird_type;
};

#ifndef _DEBUG  // airplaneView.cpp의 디버그 버전
inline CairplaneDoc* CairplaneView::GetDocument() const
   { return reinterpret_cast<CairplaneDoc*>(m_pDocument); }
#endif

