/**
 * @file /dslam_viewer/src/lib/simple_dialog.cpp
 * 
 * @brief Short description of this file.
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include "simple_dialog.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace dslam_viewer {

CSimpleDialog::CSimpleDialog(QWidget *parent): QDialog(parent)
{
        setupUi(this);
        // Set label text
        m_pLabel->setText("Simple dialog correctly initialized");
        // Set signal and slot for "OK Button"
        connect(m_pOkButton, SIGNAL(clicked()), this, SLOT(OkButtonClicked()));
}

void CSimpleDialog::OkButtonClicked()
{
        m_pLabel->setText("OK Button clicked ...");
}

} // namespace dslam_viewer
