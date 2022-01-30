procedure InitializeComponent;
    begin
        self.pictureBox1 := new System.Windows.Forms.PictureBox();
        self.label1 := new System.Windows.Forms.Label();
        self.label2 := new System.Windows.Forms.Label();
        self.button1 := new System.Windows.Forms.Button();
        self.maskedTextBox1 := new System.Windows.Forms.MaskedTextBox();
        self.label3 := new System.Windows.Forms.Label();
        self.button2 := new System.Windows.Forms.Button();
        (System.ComponentModel.ISupportInitialize(self.pictureBox1)).BeginInit();
        self.SuspendLayout();
        // 
        // pictureBox1
        // 
        self.pictureBox1.Location := new System.Drawing.Point(12, 27);
        self.pictureBox1.Name := 'pictureBox1';
        self.pictureBox1.Size := new System.Drawing.Size(838, 509);
        self.pictureBox1.TabIndex := 1;
        self.pictureBox1.TabStop := false;
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(12, 9);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(243, 15);
        self.label1.TabIndex := 2;
        self.label1.Text := 'Количество выпущенного товара в тыс. штук';
        self.label1.TextAlign := System.Drawing.ContentAlignment.BottomLeft;
        self.label1.Click += label1_Click;
        // 
        // label2
        // 
        self.label2.Location := new System.Drawing.Point(801, 539);
        self.label2.Name := 'label2';
        self.label2.Size := new System.Drawing.Size(49, 16);
        self.label2.TabIndex := 3;
        self.label2.Text := 'Год';
        self.label2.TextAlign := System.Drawing.ContentAlignment.TopRight;
        self.label2.Click += label2_Click;
        // 
        // button1
        // 
        self.button1.Location := new System.Drawing.Point(903, 144);
        self.button1.Name := 'button1';
        self.button1.Size := new System.Drawing.Size(75, 23);
        self.button1.TabIndex := 4;
        self.button1.Text := 'Ввод';
        self.button1.UseVisualStyleBackColor := true;
        self.button1.Click += button1_Click;
        // 
        // maskedTextBox1
        // 
        self.maskedTextBox1.Location := new System.Drawing.Point(890, 118);
        self.maskedTextBox1.Name := 'maskedTextBox1';
        self.maskedTextBox1.Size := new System.Drawing.Size(100, 20);
        self.maskedTextBox1.TabIndex := 5;
        // 
        // label3
        // 
        self.label3.Location := new System.Drawing.Point(863, 92);
        self.label3.Name := 'label3';
        self.label3.Size := new System.Drawing.Size(153, 23);
        self.label3.TabIndex := 6;
        self.label3.Text := 'Введите название продукта';
        // 
        // button2
        // 
        self.button2.Location := new System.Drawing.Point(903, 173);
        self.button2.Name := 'button2';
        self.button2.Size := new System.Drawing.Size(75, 23);
        self.button2.TabIndex := 7;
        self.button2.Text := 'Сброс';
        self.button2.UseVisualStyleBackColor := true;
        self.button2.Click += button2_Click;
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(1028, 558);
        self.Controls.Add(self.button2);
        self.Controls.Add(self.label3);
        self.Controls.Add(self.maskedTextBox1);
        self.Controls.Add(self.button1);
        self.Controls.Add(self.label2);
        self.Controls.Add(self.label1);
        self.Controls.Add(self.pictureBox1);
        self.Name := 'Form1';
        self.Text := 'График поступления товара по годам';
        (System.ComponentModel.ISupportInitialize(self.pictureBox1)).EndInit();
        self.ResumeLayout(false);
        self.PerformLayout();
    end;
