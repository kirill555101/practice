procedure InitializeComponent;
    begin
        self.button2 := new System.Windows.Forms.Button();
        self.button1 := new System.Windows.Forms.Button();
        self.button3 := new System.Windows.Forms.Button();
        self.maskedTextBox3 := new System.Windows.Forms.MaskedTextBox();
        self.label3 := new System.Windows.Forms.Label();
        self.maskedTextBox2 := new System.Windows.Forms.MaskedTextBox();
        self.label2 := new System.Windows.Forms.Label();
        self.maskedTextBox1 := new System.Windows.Forms.MaskedTextBox();
        self.label1 := new System.Windows.Forms.Label();
        self.SuspendLayout();
        // 
        // button2
        // 
        self.button2.Location := new System.Drawing.Point(262, 210);
        self.button2.Name := 'button2';
        self.button2.Size := new System.Drawing.Size(119, 45);
        self.button2.TabIndex := 19;
        self.button2.Text := 'Назад';
        self.button2.UseVisualStyleBackColor := true;
        self.button2.Click += button2_Click;
        // 
        // button1
        // 
        self.button1.Location := new System.Drawing.Point(12, 210);
        self.button1.Name := 'button1';
        self.button1.Size := new System.Drawing.Size(119, 45);
        self.button1.TabIndex := 18;
        self.button1.Text := 'Удалить';
        self.button1.UseVisualStyleBackColor := true;
        self.button1.Click += button1_Click;
        // 
        // button3
        // 
        self.button3.Location := new System.Drawing.Point(137, 210);
        self.button3.Name := 'button3';
        self.button3.Size := new System.Drawing.Size(119, 45);
        self.button3.TabIndex := 20;
        self.button3.Text := 'Удалить все';
        self.button3.UseVisualStyleBackColor := true;
        self.button3.Click += button3_Click;
        // 
        // maskedTextBox3
        // 
        self.maskedTextBox3.Location := new System.Drawing.Point(117, 166);
        self.maskedTextBox3.Mask := '0000';
        self.maskedTextBox3.Name := 'maskedTextBox3';
        self.maskedTextBox3.Size := new System.Drawing.Size(176, 20);
        self.maskedTextBox3.TabIndex := 26;
        self.maskedTextBox3.ValidatingType := typeof(System.Int32);
        // 
        // label3
        // 
        self.label3.Location := new System.Drawing.Point(117, 140);
        self.label3.Name := 'label3';
        self.label3.Size := new System.Drawing.Size(176, 23);
        self.label3.TabIndex := 25;
        self.label3.Text := 'Введите год переписи';
        // 
        // maskedTextBox2
        // 
        self.maskedTextBox2.Location := new System.Drawing.Point(117, 105);
        self.maskedTextBox2.Mask := '000000000';
        self.maskedTextBox2.Name := 'maskedTextBox2';
        self.maskedTextBox2.Size := new System.Drawing.Size(176, 20);
        self.maskedTextBox2.TabIndex := 24;
        // 
        // label2
        // 
        self.label2.Location := new System.Drawing.Point(117, 79);
        self.label2.Name := 'label2';
        self.label2.Size := new System.Drawing.Size(176, 23);
        self.label2.TabIndex := 23;
        self.label2.Text := 'Введите численность населения';
        // 
        // maskedTextBox1
        // 
        self.maskedTextBox1.Location := new System.Drawing.Point(117, 47);
        self.maskedTextBox1.Name := 'maskedTextBox1';
        self.maskedTextBox1.Size := new System.Drawing.Size(176, 20);
        self.maskedTextBox1.TabIndex := 22;
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(117, 21);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(176, 23);
        self.label1.TabIndex := 21;
        self.label1.Text := 'Введите название города';
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(393, 273);
        self.Controls.Add(self.maskedTextBox3);
        self.Controls.Add(self.label3);
        self.Controls.Add(self.maskedTextBox2);
        self.Controls.Add(self.label2);
        self.Controls.Add(self.maskedTextBox1);
        self.Controls.Add(self.label1);
        self.Controls.Add(self.button3);
        self.Controls.Add(self.button2);
        self.Controls.Add(self.button1);
        self.Name := 'Form1';
        self.Text := 'Удаление данных';
        self.ResumeLayout(false);
        self.PerformLayout();
    end;
