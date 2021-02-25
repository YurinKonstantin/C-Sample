//
// MainPage.xaml.cpp
// Реализация класса MainPage.
//

#include "pch.h"
#include "MainPage.xaml.h"
using namespace Concurrency;
using namespace Windows::Storage::Pickers;
using namespace Windows::Storage;

using namespace App3;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// Документацию по шаблону элемента "Пустая страница" см. по адресу https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x419

MainPage::MainPage()
{
	InitializeComponent();
}


void App3::MainPage::Button_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
    
    OpenFolder();
}
void App3::MainPage::OpenFile()//Открывает выбранный файл
{
    // STORAGE FILE
   //StorageFile^ saveFile;

   // FILE PICKER, FOR SELECTING A SAVE FILE
  FileOpenPicker^ filePicker = ref new FileOpenPicker;
  //  FolderPicker^ folderPicker = ref new FolderPicker;
    // ARRAY OF FILE TYPES
    Array<String^>^ fileTypes = ref new Array<String^>(1);
    fileTypes->Data[0] = "*";

    // filePicker->ViewMode = PickerViewMode::Thumbnail;
     filePicker->SuggestedStartLocation = PickerLocationId::Desktop;
     filePicker->FileTypeFilter->ReplaceAll(fileTypes);
 

    // THIS SHOULD HOPEFULLY LET US PICK A FILE
    create_task(filePicker->PickSingleFileAsync()).then([this](StorageFile^ saveFile)
        {
            if (saveFile)
            {
                //do some stuff
                tt->Text = saveFile->Name;//folder:
            }
            else
            {
                tt->Text = "Erorr";//folder:
            }
        });
}
void App3::MainPage::OpenFolder()//Открывает выбранную папку
{
    // STORAGE FILE
  // StorageFile^ saveFile;

   // FILE PICKER, FOR SELECTING A SAVE FILE
 // FileOpenPicker^ filePicker = ref new FileOpenPicker;
    FolderPicker^ folderPicker = ref new FolderPicker;
    // ARRAY OF FILE TYPES
    Array<String^>^ fileTypes = ref new Array<String^>(1);
    fileTypes->Data[0] = "*";

    // filePicker->ViewMode = PickerViewMode::Thumbnail;
    // filePicker->SuggestedStartLocation = PickerLocationId::Desktop;
   //  filePicker->FileTypeFilter->ReplaceAll(fileTypes);
    folderPicker->SuggestedStartLocation = PickerLocationId::Desktop;
    folderPicker->FileTypeFilter->ReplaceAll(fileTypes);
    // THIS SHOULD HOPEFULLY LET US PICK A FILE
    create_task(folderPicker->PickSingleFolderAsync()).then([this](StorageFolder^ folder)
        {
            if (folder)
            {
                //do some stuff
                tt->Text = folder->Name;//folder:
            }
            else
            {
                tt->Text = "Erorr";//folder:
            }
        });
}
