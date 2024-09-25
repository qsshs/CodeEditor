#pragma once

// Qt
#include <QWidget> // Required for inheritance

class CodeEditor;
class QSyntaxStyle;

/**
 * @brief Class, that describes line number area widget.
 */
class QLineNumberArea : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief Constructor.
     * @param parent Pointer to parent QTextEdit widget.
     */
    explicit QLineNumberArea(CodeEditor* parent=nullptr);

    // Disable copying
    QLineNumberArea(const QLineNumberArea&) = delete;
    QLineNumberArea& operator=(const QLineNumberArea&) = delete;

    /**
     * @brief Overridden method for getting line number area
     * size.
     */
    QSize sizeHint() const override;

    /**
     * @brief Method for setting syntax style object.
     * @param style Pointer to syntax style.
     */
    void setSyntaxStyle(QSyntaxStyle* style);

    /**
     * @brief Method for getting syntax style.
     * @return Pointer to syntax style.
     */
    QSyntaxStyle* syntaxStyle() const;

protected:
    void paintEvent(QPaintEvent* event) override;

private:

    QSyntaxStyle* m_syntaxStyle;

    CodeEditor* m_codeEditParent;

};

