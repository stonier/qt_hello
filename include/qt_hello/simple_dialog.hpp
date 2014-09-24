/**
 * @file /dslam_viewer/src/lib/simple_dialog.hpp
 * 
 * @brief Short description of this file.
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef dslam_viewer_SIMPLE_DIALOG_HPP_
#define dslam_viewer_SIMPLE_DIALOG_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include "ui_simpledialog.h"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace dslam_viewer {


class CSimpleDialog : public QDialog, private Ui::CSimpleDialog
{
                Q_OBJECT

        private slots:

                void OkButtonClicked();
        public:
                CSimpleDialog(QWidget *parent = 0);
                ~CSimpleDialog(){}
};

} // namespace dslam_viewer

#endif /* dslam_viewer_SIMPLE_DIALOG_HPP_ */
