#include "PreProcessor.h"
#include "Processor.h"
#include "PostProcessor.h"

System::Void SAPR::PostProcessor::�������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	SAPR::PreProcessor PreProcessor;
	PreProcessor.ShowDialog();
	this->Close();
	return System::Void();
}

System::Void SAPR::PostProcessor::�������ToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Hide();
	SAPR::Processor Processor;
	Processor.ShowDialog();
	this->Close();
	return System::Void();
}
