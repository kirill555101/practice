procedure InitializeComponent;
    begin
        self.maskedTextBox3 := new System.Windows.Forms.MaskedTextBox();
        self.maskedTextBox2 := new System.Windows.Forms.MaskedTextBox();
        self.label5 := new System.Windows.Forms.Label();
        self.label4 := new System.Windows.Forms.Label();
        self.label3 := new System.Windows.Forms.Label();
        self.maskedTextBox1 := new System.Windows.Forms.MaskedTextBox();
        self.label2 := new System.Windows.Forms.Label();
        self.button1 := new System.Windows.Forms.Button();
        self.label1 := new System.Windows.Forms.Label();
        self.SuspendLayout();
        // 
        // maskedTextBox3
        // 
        self.maskedTextBox3.Location := new System.Drawing.Point(172, 126);
        self.maskedTextBox3.Name := 'maskedTextBox3';
        self.maskedTextBox3.Size := new System.Drawing.Size(69, 20);
        self.maskedTextBox3.TabIndex := 29;
        // 
        // maskedTextBox2
        // 
        self.maskedTextBox2.Location := new System.Drawing.Point(41, 126);
        self.maskedTextBox2.Name := 'maskedTextBox2';
        self.maskedTextBox2.Size := new System.Drawing.Size(69, 20);
        self.maskedTextBox2.TabIndex := 28;
        // 
        // label5
        // 
        self.label5.Location := new System.Drawing.Point(116, 126);
        self.label5.Name := 'label5';
        self.label5.Size := new System.Drawing.Size(50, 20);
        self.label5.TabIndex := 27;
        self.label5.Text := 'года по';
        self.label5.TextAlign := System.Drawing.ContentAlignment.MiddleCenter;
        // 
        // label4
        // 
        self.label4.Location := new System.Drawing.Point(11, 126);
        self.label4.Name := 'label4';
        self.label4.Size := new System.Drawing.Size(24, 20);
        self.label4.TabIndex := 26;
        self.label4.Text := 'С';
        self.label4.TextAlign := System.Drawing.ContentAlignment.MiddleCenter;
        // 
        // label3
        // 
        self.label3.Location := new System.Drawing.Point(53, 91);
        self.label3.Name := 'label3';
        self.label3.Size := new System.Drawing.Size(171, 23);
        self.label3.TabIndex := 25;
        self.label3.Text := 'Введите период';
        self.label3.TextAlign := System.Drawing.ContentAlignment.TopCenter;
        // 
        // maskedTextBox1
        // 
        self.maskedTextBox1.Location := new System.Drawing.Point(54, 57);
        self.maskedTextBox1.Name := 'maskedTextBox1';
        self.maskedTextBox1.Size := new System.Drawing.Size(171, 20);
        self.maskedTextBox1.TabIndex := 24;
        // 
        // label2
        // 
        self.label2.Location := new System.Drawing.Point(54, 31);
        self.label2.Name := 'label2';
        self.label2.Size := new System.Drawing.Size(171, 23);
        self.label2.TabIndex := 23;
        self.label2.Text := 'Введите имя разработчика';
        self.label2.TextAlign := System.Drawing.ContentAlignment.TopCenter;
        // 
        // button1
        // 
        self.button1.Location := new System.Drawing.Point(81, 172);
        self.button1.Name := 'button1';
        self.button1.Size := new System.Drawing.Size(112, 44);
        self.button1.TabIndex := 30;
        self.button1.Text := 'Ввод';
        self.button1.UseVisualStyleBackColor := true;
        self.button1.Click += button3_Click;
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(247, 126);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(24, 20);
        self.label1.TabIndex := 31;
        self.label1.Text := 'год';
        self.label1.TextAlign := System.Drawing.ContentAlignment.MiddleCenter;
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(290, 228);
        self.Controls.Add(self.label1);
        self.Controls.Add(self.button1);
        self.Controls.Add(self.maskedTextBox3);
        self.Controls.Add(self.maskedTextBox2);
        self.Controls.Add(self.label5);
        self.Controls.Add(self.label4);
        self.Controls.Add(self.label3);
        self.Controls.Add(self.maskedTextBox1);
        self.Controls.Add(self.label2);
        self.Name := 'Form1';
        self.Text := 'Поиск за промежуток';
        self.ResumeLayout(false);
        self.PerformLayout();
    end;
