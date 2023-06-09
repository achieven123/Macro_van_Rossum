 namespace Winforms_Calculator
{
    partial class Form1
    {
        /// <summary>
        /// 필수 디자이너 변수입니다.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 사용 중인 모든 리소스를 정리합니다.
        /// </summary>
        /// <param name="disposing">관리되는 리소스를 삭제해야 하면 true이고, 그렇지 않으면 false입니다.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form 디자이너에서 생성한 코드

        /// <summary>
        /// 디자이너 지원에 필요한 메서드입니다. 
        /// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
        /// </summary>
        private void InitializeComponent()
        {
            this.numpad0 = new System.Windows.Forms.Button();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.numpad1 = new System.Windows.Forms.Button();
            this.numpad2 = new System.Windows.Forms.Button();
            this.numpad3 = new System.Windows.Forms.Button();
            this.numpad4 = new System.Windows.Forms.Button();
            this.numpad5 = new System.Windows.Forms.Button();
            this.numpad6 = new System.Windows.Forms.Button();
            this.numpad7 = new System.Windows.Forms.Button();
            this.numpad8 = new System.Windows.Forms.Button();
            this.numpad9 = new System.Windows.Forms.Button();
            this.delete = new System.Windows.Forms.Button();
            this.clear = new System.Windows.Forms.Button();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.numBox1 = new System.Windows.Forms.TextBox();
            this.numBox2 = new System.Windows.Forms.TextBox();
            this.divide = new System.Windows.Forms.Button();
            this.product = new System.Windows.Forms.Button();
            this.plus = new System.Windows.Forms.Button();
            this.equal = new System.Windows.Forms.Button();
            this.negate = new System.Windows.Forms.Button();
            this.remainder = new System.Windows.Forms.Button();
            this.clearEntry = new System.Windows.Forms.Button();
            this.button10 = new System.Windows.Forms.Button();
            this.button11 = new System.Windows.Forms.Button();
            this.button12 = new System.Windows.Forms.Button();
            this.minus = new System.Windows.Forms.Button();
            this.button9 = new System.Windows.Forms.Button();
            this.tableLayoutPanel3 = new System.Windows.Forms.TableLayoutPanel();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.button5 = new System.Windows.Forms.Button();
            this.tableLayoutPanel1.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.tableLayoutPanel3.SuspendLayout();
            this.SuspendLayout();
            // 
            // numpad0
            // 
            this.numpad0.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.numpad0.Dock = System.Windows.Forms.DockStyle.Fill;
            this.numpad0.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.numpad0.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.numpad0.Location = new System.Drawing.Point(98, 470);
            this.numpad0.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.numpad0.Name = "numpad0";
            this.numpad0.Size = new System.Drawing.Size(89, 54);
            this.numpad0.TabIndex = 1;
            this.numpad0.Text = "0";
            this.numpad0.UseVisualStyleBackColor = false;
            this.numpad0.Click += new System.EventHandler(this.numpad_Click);
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.tableLayoutPanel1.ColumnCount = 4;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 25F));
            this.tableLayoutPanel1.Controls.Add(this.numpad0, 1, 7);
            this.tableLayoutPanel1.Controls.Add(this.numpad1, 0, 6);
            this.tableLayoutPanel1.Controls.Add(this.numpad2, 1, 6);
            this.tableLayoutPanel1.Controls.Add(this.numpad3, 2, 6);
            this.tableLayoutPanel1.Controls.Add(this.numpad4, 0, 5);
            this.tableLayoutPanel1.Controls.Add(this.numpad5, 1, 5);
            this.tableLayoutPanel1.Controls.Add(this.numpad6, 2, 5);
            this.tableLayoutPanel1.Controls.Add(this.numpad7, 0, 4);
            this.tableLayoutPanel1.Controls.Add(this.numpad8, 1, 4);
            this.tableLayoutPanel1.Controls.Add(this.numpad9, 2, 4);
            this.tableLayoutPanel1.Controls.Add(this.delete, 3, 2);
            this.tableLayoutPanel1.Controls.Add(this.clear, 2, 2);
            this.tableLayoutPanel1.Controls.Add(this.tableLayoutPanel2, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.divide, 3, 3);
            this.tableLayoutPanel1.Controls.Add(this.product, 3, 4);
            this.tableLayoutPanel1.Controls.Add(this.plus, 3, 6);
            this.tableLayoutPanel1.Controls.Add(this.equal, 3, 7);
            this.tableLayoutPanel1.Controls.Add(this.negate, 0, 7);
            this.tableLayoutPanel1.Controls.Add(this.remainder, 0, 2);
            this.tableLayoutPanel1.Controls.Add(this.clearEntry, 1, 2);
            this.tableLayoutPanel1.Controls.Add(this.button10, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.button11, 1, 3);
            this.tableLayoutPanel1.Controls.Add(this.button12, 2, 3);
            this.tableLayoutPanel1.Controls.Add(this.minus, 3, 5);
            this.tableLayoutPanel1.Controls.Add(this.button9, 2, 7);
            this.tableLayoutPanel1.Controls.Add(this.tableLayoutPanel3, 0, 1);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel1.Font = new System.Drawing.Font("맑은 고딕", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel1.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 8;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 112F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 14.28571F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 14.28571F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 14.28571F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 14.28571F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 14.28571F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 14.28571F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 14.28571F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(382, 528);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // numpad1
            // 
            this.numpad1.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.numpad1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.numpad1.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.numpad1.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.numpad1.Location = new System.Drawing.Point(3, 411);
            this.numpad1.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.numpad1.Name = "numpad1";
            this.numpad1.Size = new System.Drawing.Size(89, 51);
            this.numpad1.TabIndex = 2;
            this.numpad1.Text = "1";
            this.numpad1.UseVisualStyleBackColor = false;
            this.numpad1.Click += new System.EventHandler(this.numpad_Click);
            // 
            // numpad2
            // 
            this.numpad2.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.numpad2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.numpad2.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.numpad2.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.numpad2.Location = new System.Drawing.Point(98, 411);
            this.numpad2.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.numpad2.Name = "numpad2";
            this.numpad2.Size = new System.Drawing.Size(89, 51);
            this.numpad2.TabIndex = 3;
            this.numpad2.Text = "2";
            this.numpad2.UseVisualStyleBackColor = false;
            this.numpad2.Click += new System.EventHandler(this.numpad_Click);
            // 
            // numpad3
            // 
            this.numpad3.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.numpad3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.numpad3.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.numpad3.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.numpad3.Location = new System.Drawing.Point(193, 411);
            this.numpad3.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.numpad3.Name = "numpad3";
            this.numpad3.Size = new System.Drawing.Size(89, 51);
            this.numpad3.TabIndex = 4;
            this.numpad3.Text = "3";
            this.numpad3.UseVisualStyleBackColor = false;
            this.numpad3.Click += new System.EventHandler(this.numpad_Click);
            // 
            // numpad4
            // 
            this.numpad4.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.numpad4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.numpad4.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.numpad4.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.numpad4.Location = new System.Drawing.Point(3, 352);
            this.numpad4.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.numpad4.Name = "numpad4";
            this.numpad4.Size = new System.Drawing.Size(89, 51);
            this.numpad4.TabIndex = 5;
            this.numpad4.Text = "4";
            this.numpad4.UseVisualStyleBackColor = false;
            this.numpad4.Click += new System.EventHandler(this.numpad_Click);
            // 
            // numpad5
            // 
            this.numpad5.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.numpad5.Dock = System.Windows.Forms.DockStyle.Fill;
            this.numpad5.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.numpad5.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.numpad5.Location = new System.Drawing.Point(98, 352);
            this.numpad5.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.numpad5.Name = "numpad5";
            this.numpad5.Size = new System.Drawing.Size(89, 51);
            this.numpad5.TabIndex = 6;
            this.numpad5.Text = "5";
            this.numpad5.UseVisualStyleBackColor = false;
            this.numpad5.Click += new System.EventHandler(this.numpad_Click);
            // 
            // numpad6
            // 
            this.numpad6.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.numpad6.Dock = System.Windows.Forms.DockStyle.Fill;
            this.numpad6.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.numpad6.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.numpad6.Location = new System.Drawing.Point(193, 352);
            this.numpad6.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.numpad6.Name = "numpad6";
            this.numpad6.Size = new System.Drawing.Size(89, 51);
            this.numpad6.TabIndex = 7;
            this.numpad6.Text = "6";
            this.numpad6.UseVisualStyleBackColor = false;
            this.numpad6.Click += new System.EventHandler(this.numpad_Click);
            // 
            // numpad7
            // 
            this.numpad7.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.numpad7.Dock = System.Windows.Forms.DockStyle.Fill;
            this.numpad7.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.numpad7.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.numpad7.Location = new System.Drawing.Point(3, 293);
            this.numpad7.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.numpad7.Name = "numpad7";
            this.numpad7.Size = new System.Drawing.Size(89, 51);
            this.numpad7.TabIndex = 8;
            this.numpad7.Text = "7";
            this.numpad7.UseVisualStyleBackColor = false;
            this.numpad7.Click += new System.EventHandler(this.numpad_Click);
            // 
            // numpad8
            // 
            this.numpad8.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.numpad8.Dock = System.Windows.Forms.DockStyle.Fill;
            this.numpad8.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.numpad8.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.numpad8.Location = new System.Drawing.Point(98, 293);
            this.numpad8.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.numpad8.Name = "numpad8";
            this.numpad8.Size = new System.Drawing.Size(89, 51);
            this.numpad8.TabIndex = 9;
            this.numpad8.Text = "8";
            this.numpad8.UseVisualStyleBackColor = false;
            this.numpad8.Click += new System.EventHandler(this.numpad_Click);
            // 
            // numpad9
            // 
            this.numpad9.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.numpad9.Dock = System.Windows.Forms.DockStyle.Fill;
            this.numpad9.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.numpad9.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.numpad9.Location = new System.Drawing.Point(193, 293);
            this.numpad9.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.numpad9.Name = "numpad9";
            this.numpad9.Size = new System.Drawing.Size(89, 51);
            this.numpad9.TabIndex = 10;
            this.numpad9.Text = "9";
            this.numpad9.UseVisualStyleBackColor = false;
            this.numpad9.Click += new System.EventHandler(this.numpad_Click);
            // 
            // delete
            // 
            this.delete.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.delete.Dock = System.Windows.Forms.DockStyle.Fill;
            this.delete.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.delete.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.delete.Location = new System.Drawing.Point(288, 175);
            this.delete.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.delete.Name = "delete";
            this.delete.Size = new System.Drawing.Size(91, 51);
            this.delete.TabIndex = 11;
            this.delete.Text = "DEL";
            this.delete.UseVisualStyleBackColor = false;
            this.delete.Click += new System.EventHandler(this.backspace_Click);
            // 
            // clear
            // 
            this.clear.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.clear.Dock = System.Windows.Forms.DockStyle.Fill;
            this.clear.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.clear.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.clear.Location = new System.Drawing.Point(193, 175);
            this.clear.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.clear.Name = "clear";
            this.clear.Size = new System.Drawing.Size(89, 51);
            this.clear.TabIndex = 12;
            this.clear.Text = "C";
            this.clear.UseVisualStyleBackColor = false;
            this.clear.Click += new System.EventHandler(this.clear_Click);
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.tableLayoutPanel2.ColumnCount = 1;
            this.tableLayoutPanel1.SetColumnSpan(this.tableLayoutPanel2, 4);
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel2.Controls.Add(this.numBox1, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.numBox2, 0, 1);
            this.tableLayoutPanel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel2.Location = new System.Drawing.Point(0, 0);
            this.tableLayoutPanel2.Margin = new System.Windows.Forms.Padding(0);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 2;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 30F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 70F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(382, 112);
            this.tableLayoutPanel2.TabIndex = 13;
            // 
            // numBox1
            // 
            this.numBox1.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.numBox1.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numBox1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.numBox1.Font = new System.Drawing.Font("굴림", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.numBox1.ForeColor = System.Drawing.SystemColors.WindowFrame;
            this.numBox1.Location = new System.Drawing.Point(17, 19);
            this.numBox1.Margin = new System.Windows.Forms.Padding(17, 19, 17, 0);
            this.numBox1.Name = "numBox1";
            this.numBox1.Size = new System.Drawing.Size(348, 20);
            this.numBox1.TabIndex = 1;
            this.numBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // numBox2
            // 
            this.numBox2.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.numBox2.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.numBox2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.numBox2.Font = new System.Drawing.Font("맑은 고딕", 30F, System.Drawing.FontStyle.Bold);
            this.numBox2.Location = new System.Drawing.Point(17, 33);
            this.numBox2.Margin = new System.Windows.Forms.Padding(17, 0, 17, 0);
            this.numBox2.MaxLength = 20;
            this.numBox2.Name = "numBox2";
            this.numBox2.Size = new System.Drawing.Size(348, 67);
            this.numBox2.TabIndex = 0;
            this.numBox2.Text = "0";
            this.numBox2.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // divide
            // 
            this.divide.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.divide.Dock = System.Windows.Forms.DockStyle.Fill;
            this.divide.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.divide.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.divide.Location = new System.Drawing.Point(288, 234);
            this.divide.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.divide.Name = "divide";
            this.divide.Size = new System.Drawing.Size(91, 51);
            this.divide.TabIndex = 14;
            this.divide.Text = "÷";
            this.divide.UseVisualStyleBackColor = false;
            this.divide.Click += new System.EventHandler(this.operator2_Click);
            // 
            // product
            // 
            this.product.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.product.Dock = System.Windows.Forms.DockStyle.Fill;
            this.product.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.product.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.product.Location = new System.Drawing.Point(288, 293);
            this.product.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.product.Name = "product";
            this.product.Size = new System.Drawing.Size(91, 51);
            this.product.TabIndex = 15;
            this.product.Text = "×";
            this.product.UseVisualStyleBackColor = false;
            this.product.Click += new System.EventHandler(this.operator2_Click);
            // 
            // plus
            // 
            this.plus.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.plus.Dock = System.Windows.Forms.DockStyle.Fill;
            this.plus.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.plus.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.plus.Location = new System.Drawing.Point(288, 411);
            this.plus.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.plus.Name = "plus";
            this.plus.Size = new System.Drawing.Size(91, 51);
            this.plus.TabIndex = 17;
            this.plus.Text = "＋";
            this.plus.UseVisualStyleBackColor = false;
            this.plus.Click += new System.EventHandler(this.operator2_Click);
            // 
            // equal
            // 
            this.equal.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.equal.Dock = System.Windows.Forms.DockStyle.Fill;
            this.equal.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.equal.Font = new System.Drawing.Font("맑은 고딕", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(129)));
            this.equal.ForeColor = System.Drawing.Color.White;
            this.equal.Location = new System.Drawing.Point(288, 470);
            this.equal.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.equal.Name = "equal";
            this.equal.Size = new System.Drawing.Size(91, 54);
            this.equal.TabIndex = 18;
            this.equal.Text = "＝";
            this.equal.UseVisualStyleBackColor = false;
            this.equal.Click += new System.EventHandler(this.equal_Click);
            // 
            // negate
            // 
            this.negate.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.negate.Dock = System.Windows.Forms.DockStyle.Fill;
            this.negate.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.negate.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.negate.Location = new System.Drawing.Point(3, 470);
            this.negate.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.negate.Name = "negate";
            this.negate.Size = new System.Drawing.Size(89, 54);
            this.negate.TabIndex = 19;
            this.negate.Text = "＋/－";
            this.negate.UseVisualStyleBackColor = false;
            this.negate.Click += new System.EventHandler(this.operator1_Click);
            // 
            // remainder
            // 
            this.remainder.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.remainder.Dock = System.Windows.Forms.DockStyle.Fill;
            this.remainder.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.remainder.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.remainder.Location = new System.Drawing.Point(3, 175);
            this.remainder.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.remainder.Name = "remainder";
            this.remainder.Size = new System.Drawing.Size(89, 51);
            this.remainder.TabIndex = 20;
            this.remainder.Text = "%";
            this.remainder.UseVisualStyleBackColor = false;
            this.remainder.Click += new System.EventHandler(this.operator2_Click);
            // 
            // clearEntry
            // 
            this.clearEntry.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.clearEntry.Dock = System.Windows.Forms.DockStyle.Fill;
            this.clearEntry.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.clearEntry.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.clearEntry.Location = new System.Drawing.Point(98, 175);
            this.clearEntry.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.clearEntry.Name = "clearEntry";
            this.clearEntry.Size = new System.Drawing.Size(89, 51);
            this.clearEntry.TabIndex = 21;
            this.clearEntry.Text = "CE";
            this.clearEntry.UseVisualStyleBackColor = false;
            this.clearEntry.Click += new System.EventHandler(this.clearEntry_Click);
            // 
            // button10
            // 
            this.button10.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.button10.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button10.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.button10.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.button10.Location = new System.Drawing.Point(3, 234);
            this.button10.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.button10.Name = "button10";
            this.button10.Size = new System.Drawing.Size(89, 51);
            this.button10.TabIndex = 22;
            this.button10.Text = "1/x";
            this.button10.UseVisualStyleBackColor = false;
            this.button10.Click += new System.EventHandler(this.operator1_Click);
            // 
            // button11
            // 
            this.button11.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.button11.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button11.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.button11.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.button11.Location = new System.Drawing.Point(98, 234);
            this.button11.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.button11.Name = "button11";
            this.button11.Size = new System.Drawing.Size(89, 51);
            this.button11.TabIndex = 22;
            this.button11.Text = "1/x²";
            this.button11.UseVisualStyleBackColor = false;
            this.button11.Click += new System.EventHandler(this.operator1_Click);
            // 
            // button12
            // 
            this.button12.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.button12.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button12.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.button12.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.button12.Location = new System.Drawing.Point(193, 234);
            this.button12.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.button12.Name = "button12";
            this.button12.Size = new System.Drawing.Size(89, 51);
            this.button12.TabIndex = 22;
            this.button12.Text = "²√x";
            this.button12.UseVisualStyleBackColor = false;
            this.button12.Click += new System.EventHandler(this.operator1_Click);
            // 
            // minus
            // 
            this.minus.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.minus.Dock = System.Windows.Forms.DockStyle.Fill;
            this.minus.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.minus.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.minus.Location = new System.Drawing.Point(288, 352);
            this.minus.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.minus.Name = "minus";
            this.minus.Size = new System.Drawing.Size(91, 51);
            this.minus.TabIndex = 16;
            this.minus.Text = "－";
            this.minus.UseVisualStyleBackColor = false;
            this.minus.Click += new System.EventHandler(this.operator2_Click);
            // 
            // button9
            // 
            this.button9.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.button9.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button9.FlatStyle = System.Windows.Forms.FlatStyle.System;
            this.button9.Font = new System.Drawing.Font("맑은 고딕", 15F);
            this.button9.Location = new System.Drawing.Point(193, 470);
            this.button9.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.button9.Name = "button9";
            this.button9.Size = new System.Drawing.Size(89, 54);
            this.button9.TabIndex = 22;
            this.button9.Text = ".";
            this.button9.UseVisualStyleBackColor = false;
            this.button9.Click += new System.EventHandler(this.operator1_Click);
            // 
            // tableLayoutPanel3
            // 
            this.tableLayoutPanel3.ColumnCount = 5;
            this.tableLayoutPanel1.SetColumnSpan(this.tableLayoutPanel3, 4);
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 16.66667F));
            this.tableLayoutPanel3.Controls.Add(this.button5, 4, 0);
            this.tableLayoutPanel3.Controls.Add(this.button4, 3, 0);
            this.tableLayoutPanel3.Controls.Add(this.button3, 2, 0);
            this.tableLayoutPanel3.Controls.Add(this.button2, 1, 0);
            this.tableLayoutPanel3.Controls.Add(this.button1, 0, 0);
            this.tableLayoutPanel3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel3.Location = new System.Drawing.Point(3, 116);
            this.tableLayoutPanel3.Margin = new System.Windows.Forms.Padding(3, 4, 3, 4);
            this.tableLayoutPanel3.Name = "tableLayoutPanel3";
            this.tableLayoutPanel3.RowCount = 1;
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel3.Size = new System.Drawing.Size(376, 51);
            this.tableLayoutPanel3.TabIndex = 23;
            // 
            // button1
            // 
            this.button1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button1.Font = new System.Drawing.Font("맑은 고딕", 10F);
            this.button1.Location = new System.Drawing.Point(3, 3);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(69, 45);
            this.button1.TabIndex = 0;
            this.button1.Text = "MC";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.memory_Click);
            // 
            // button2
            // 
            this.button2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button2.Font = new System.Drawing.Font("맑은 고딕", 10F);
            this.button2.Location = new System.Drawing.Point(78, 3);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(69, 45);
            this.button2.TabIndex = 1;
            this.button2.Text = "MR";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.memory_Click);
            // 
            // button3
            // 
            this.button3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button3.Font = new System.Drawing.Font("맑은 고딕", 10F);
            this.button3.Location = new System.Drawing.Point(153, 3);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(69, 45);
            this.button3.TabIndex = 2;
            this.button3.Text = "M+";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.memory_Click);
            // 
            // button4
            // 
            this.button4.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button4.Font = new System.Drawing.Font("맑은 고딕", 10F);
            this.button4.Location = new System.Drawing.Point(228, 3);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(69, 45);
            this.button4.TabIndex = 3;
            this.button4.Text = "M-";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.memory_Click);
            // 
            // button5
            // 
            this.button5.Dock = System.Windows.Forms.DockStyle.Fill;
            this.button5.Font = new System.Drawing.Font("맑은 고딕", 10F);
            this.button5.Location = new System.Drawing.Point(303, 3);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(70, 45);
            this.button5.TabIndex = 4;
            this.button5.Text = "MS";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.memory_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.WhiteSmoke;
            this.ClientSize = new System.Drawing.Size(382, 528);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Margin = new System.Windows.Forms.Padding(3, 2, 3, 2);
            this.MaximumSize = new System.Drawing.Size(550, 700);
            this.MinimumSize = new System.Drawing.Size(400, 575);
            this.Name = "Form1";
            this.Text = "계산기";
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            this.tableLayoutPanel3.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button numpad0;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Button numpad1;
        private System.Windows.Forms.Button numpad2;
        private System.Windows.Forms.Button numpad3;
        private System.Windows.Forms.Button numpad4;
        private System.Windows.Forms.Button numpad5;
        private System.Windows.Forms.Button numpad6;
        private System.Windows.Forms.Button numpad7;
        private System.Windows.Forms.Button numpad8;
        private System.Windows.Forms.Button numpad9;
        private System.Windows.Forms.Button delete;
        private System.Windows.Forms.Button clear;
        private System.Windows.Forms.TextBox numBox2;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.TextBox numBox1;
        private System.Windows.Forms.Button divide;
        private System.Windows.Forms.Button product;
        private System.Windows.Forms.Button minus;
        private System.Windows.Forms.Button plus;
        private System.Windows.Forms.Button equal;
        private System.Windows.Forms.Button negate;
        private System.Windows.Forms.Button remainder;
        private System.Windows.Forms.Button clearEntry;
        private System.Windows.Forms.Button button9;
        private System.Windows.Forms.Button button10;
        private System.Windows.Forms.Button button11;
        private System.Windows.Forms.Button button12;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel3;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button1;
    }
}

