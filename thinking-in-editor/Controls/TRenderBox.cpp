#include "TRenderBox.h"
#include "GlobalSetting.h"
#include "CommandDefinition.h"

TRenderBox::TRenderBox(TRenderBox* parent):
		QWidget(parent),
		Cursor(0),
		RenderFlag(false)
{
}

TRenderBox::~TRenderBox(){
    if(Cursor==0){
	delete Cursor;
    }
}

void TRenderBox::ClearRenderBox(){
    this->setAttribute(Qt::WA_UpdatesDisabled,false);
    this->repaint(0, 0, this->width(), this->height());
    this->setAttribute(Qt::WA_UpdatesDisabled,true);
}

void TRenderBox::repaint(int x, int y, int w, int h){
    
}

void TRenderBox::repaint(const QRect &){
    
}

void TRenderBox::repaint(const QRegion &){
    
}

void TRenderBox::StartRender(){
    if(!IsRender()){
	RenderFlag=true;
	CreateRenderEngine((int)this->winId());
    }
}

void TRenderBox::StopRender(){

}

void TRenderBox::RestartRender(){

}

bool TRenderBox::IsRender(){
    return RenderFlag;
}

void TRenderBox::actionEvent(QActionEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::changeEvent(QEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::closeEvent(QCloseEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::contextMenuEvent(QContextMenuEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::dragEnterEvent(QDragEnterEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::dragLeaveEvent(QDragLeaveEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::dragMoveEvent(QDragMoveEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::dropEvent(QDropEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::enterEvent(QEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<SYS_ENTEREVENT;
	PushEditorMessage(0, stringbuffer.str());
    }else{
        setCursor(Qt::ArrowCursor);
    }
}

void TRenderBox::focusInEvent(QFocusEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::focusOutEvent(QFocusEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::hideEvent(QHideEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::inputMethodEvent(QInputMethodEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::keyPressEvent(QKeyEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<SYS_KEYPRESSEVENT;
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::keyReleaseEvent(QKeyEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<SYS_KEYRELEASEEVENT;
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::leaveEvent(QEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<SYS_LEAVEEVENT;
	PushEditorMessage(0, stringbuffer.str());
    }
    setCursor(Qt::ArrowCursor);
}

void TRenderBox::mouseDoubleClickEvent(QMouseEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<SYS_MOUSEDOUBLECLICKEVENT;
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::mouseMoveEvent(QMouseEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<SYS_MOUSEMOVEEVENT<<" "<<event->x()<<" "<<event->y()<<" "<<event->button();
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::mousePressEvent(QMouseEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<SYS_MOUSEPRESSEVENT<<" "<<event->x()<<" "<<event->y()<<" "<<event->button();
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::mouseReleaseEvent(QMouseEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<SYS_MOUSERELEASEEVENT<<" "<<event->x()<<" "<<event->y()<<" "<<event->button();
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::moveEvent(QMoveEvent * event){
    if(this->IsRender()){
	const QPoint& p = event->pos();
	std::ostringstream stringbuffer;
	stringbuffer<<SYS_MOVEEVENT<<" "<<p.x()<<" "<<p.y();
	PushEditorMessage(0, stringbuffer.str());
    }
}

bool TRenderBox::nativeEvent(const QByteArray & eventType, void * message, long * result){
	return QWidget::nativeEvent(eventType,message,result);
}

void TRenderBox::paintEvent(QPaintEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::resizeEvent(QResizeEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::showEvent(QShowEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::tabletEvent(QTabletEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}

void TRenderBox::wheelEvent(QWheelEvent * event){
    if(this->IsRender()){
	std::ostringstream stringbuffer;
	stringbuffer<<"wheelEvent";
	PushEditorMessage(0, stringbuffer.str());
    }
}