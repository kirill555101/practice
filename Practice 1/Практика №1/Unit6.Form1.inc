procedure InitializeComponent;
    begin
        self.maskedTextBox1 := new System.Windows.Forms.MaskedTextBox();
        self.label2 := new System.Windows.Forms.Label();
        self.button1 := new System.Windows.Forms.Button();
        self.SuspendLayout();
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
        self.label2.Text := 'Введите объем партии';
        self.label2.TextAlign := System.Drawing.ContentAlignment.TopCenter;
        // 
        // button1
        // 
        self.button1.Location := new System.Drawing.Point(84, 83);
        self.button1.Name := 'button1';
        self.button1.Size := new System.Drawing.Size(112, 44);
        self.button1.TabIndex := 30;
        self.button1.Text := 'Ввод';
        self.button1.UseVisualStyleBackColor := true;
        self.button1.Click += button3_Click;
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(290, 145);
        self.Controls.Add(self.button1);
        self.Controls.Add(self.maskedTextBox1);
        self.Controls.Add(self.label2);
        self.Name := 'Form1';
        self.Text := 'Поиск по объему партии';
        self.ResumeLayout(false);
        self.PerformLayout();
    end;
