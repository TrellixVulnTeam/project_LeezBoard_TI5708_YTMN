#ifndef SETTINGSCREEN_H
#define SETTINGSCREEN_H

#include <qglobal.h>
#include <QtGui>

#if QT_VERSION >= 0x050000

#include <QComboBox>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QFormLayout>

#endif

class GlobalSettings;
class QKeyboardLineEdit;

class SettingScreen : public QWidget
{
    Q_OBJECT
public:
    explicit SettingScreen(QWidget *parent = 0);

    void setLicenseString(QString licenseString);
    
signals:
    void valueChanged();
    void cityChanged();
    
public slots:
    void setTempFormatF();
    void setTempFormatC();

    void setTimeFormat12h();
    void setTimeFormat24h();

    void commitChanges();
    void fillSettingValues();

protected:
    void showEvent(QShowEvent *);

private:
    QComboBox *cityBox;
    QLabel *licenseStringLabel;

    QPushButton *FButton;
    QPushButton *CButton;

    QPushButton *Button12h;
    QPushButton *Button24h;

    QKeyboardLineEdit* m_proxyHostLineEdit;
    QKeyboardLineEdit* m_proxyPortLineEdit;
    QKeyboardLineEdit* m_remoteListenPortLineEdit;

    GlobalSettings* m_globalSettings;

    QWidget* buildNetworkSettingsWidget();
    QWidget* buildGeneralSettingsWidget();
    QWidget* buildFormatSettingsWidget();
    
};

#endif // SETTINGSCREEN_H
