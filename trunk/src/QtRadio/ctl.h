/* File:   ctl.h
 * Author: Graeme Jury, ZL2APV
 *
 * Created on 16 September 2011, 17:34
 */

/* Copyright (C)
* 2011 - Graeme Jury, ZL2APV
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*
*/

#ifndef CTL_H
#define CTL_H

#include <QFrame>

namespace Ui {
    class Ctl;
}

class Ctl : public QFrame
{
    Q_OBJECT

public:
    explicit Ctl(QWidget *parent = 0);
    ~Ctl();
    int getTxPwr();
    void clearMoxBtn();

signals:
    void pttChange(int caller, bool ptt);//0 = MOX, 1 = Tune, 2 = VOX, 3 = Extern H'ware
    void pwrSlider_valueChanged(double pwr);
    void testBtnClick(bool state);
    void testSliderChange(int value);

public slots:
    void update_mic_level(qreal level);
    void HideTX(bool cantx);

private slots:
    void on_btnMox_clicked(bool checked);
    void on_btnTune_clicked(bool checked);
    void on_pwrSlider_valueChanged(int value);
    void on_checkBox_stateChanged(int arg1);
    void on_pwrSlider_2_valueChanged(int value);
    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_pressed();

    void on_pushButton_released();

    void on_pushButton_toggled(bool checked);

private:
    Ui::Ctl *ui;
    int moxPwr;
    int TunePwr;
};

#endif // CTL_H
