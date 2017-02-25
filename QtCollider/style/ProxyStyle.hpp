#ifndef PROXYSTYLE_HPP
#define PROXYSTYLE_HPP

#include <QProxyStyle>

namespace QtCollider {

class ProxyStyle : public QProxyStyle
{
public:
  ProxyStyle ( QStyle *style = 0 ) : QProxyStyle(style) { }

  virtual void drawComplexControl ( ComplexControl, const QStyleOptionComplex *,
                            QPainter *, const QWidget * w = 0 ) const;

  virtual int styleHint ( StyleHint, const QStyleOption * = 0,
                          const QWidget * = 0, QStyleHintReturn * = 0 ) const;
};

} // namespace QtCollider

#endif // PROXYSTYLE_HPP
