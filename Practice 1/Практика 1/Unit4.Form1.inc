procedure InitializeComponent;
    begin
        self.dataGridView1 := new System.Windows.Forms.DataGridView();
        self.Column1 := new System.Windows.Forms.DataGridViewTextBoxColumn();
        self.Column2 := new System.Windows.Forms.DataGridViewTextBoxColumn();
        self.Column3 := new System.Windows.Forms.DataGridViewTextBoxColumn();
        self.Column4 := new System.Windows.Forms.DataGridViewTextBoxColumn();
        self.Column5 := new System.Windows.Forms.DataGridViewTextBoxColumn();
        self.button1 := new System.Windows.Forms.Button();
        self.button2 := new System.Windows.Forms.Button();
        self.button3 := new System.Windows.Forms.Button();
        self.label1 := new System.Windows.Forms.Label();
        self.button4 := new System.Windows.Forms.Button();
        self.button5 := new System.Windows.Forms.Button();
        self.button6 := new System.Windows.Forms.Button();
        (System.ComponentModel.ISupportInitialize(self.dataGridView1)).BeginInit();
        self.SuspendLayout();
        // 
        // dataGridView1
        // 
        self.dataGridView1.AllowUserToAddRows := false;
        self.dataGridView1.AllowUserToDeleteRows := false;
        self.dataGridView1.AllowUserToResizeColumns := false;
        self.dataGridView1.AllowUserToResizeRows := false;
        self.dataGridView1.Anchor := (System.Windows.Forms.AnchorStyles(((System.Windows.Forms.AnchorStyles.Top or System.Windows.Forms.AnchorStyles.Bottom) 
                    or System.Windows.Forms.AnchorStyles.Left)));
        self.dataGridView1.ColumnHeadersHeightSizeMode := System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
        self.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[5](self.Column1, self.Column2, self.Column3, self.Column4, self.Column5));
        self.dataGridView1.Location := new System.Drawing.Point(12, 12);
        self.dataGridView1.Name := 'dataGridView1';
        self.dataGridView1.ReadOnly := true;
        self.dataGridView1.RowHeadersVisible := false;
        self.dataGridView1.Size := new System.Drawing.Size(577, 419);
        self.dataGridView1.TabIndex := 0;
        // 
        // Column1
        // 
        self.Column1.HeaderText := 'Номер';
        self.Column1.Name := 'Column1';
        self.Column1.ReadOnly := true;
        self.Column1.Width := 70;
        // 
        // Column2
        // 
        self.Column2.HeaderText := 'Название продукта';
        self.Column2.Name := 'Column2';
        self.Column2.ReadOnly := true;
        self.Column2.Width := 143;
        // 
        // Column3
        // 
        self.Column3.HeaderText := 'Дата выпуска';
        self.Column3.Name := 'Column3';
        self.Column3.ReadOnly := true;
        // 
        // Column4
        // 
        self.Column4.HeaderText := 'Разработчик';
        self.Column4.Name := 'Column4';
        self.Column4.ReadOnly := true;
        self.Column4.Width := 143;
        // 
        // Column5
        // 
        self.Column5.HeaderText := 'Требуемая ОЗУ в Гб';
        self.Column5.Name := 'Column5';
        self.Column5.ReadOnly := true;
        // 
        // button1
        // 
        self.button1.Location := new System.Drawing.Point(649, 387);
        self.button1.Name := 'button1';
        self.button1.Size := new System.Drawing.Size(112, 44);
        self.button1.TabIndex := 1;
        self.button1.Text := 'Назад';
        self.button1.UseVisualStyleBackColor := true;
        self.button1.Click += button1_Click;
        // 
        // button2
        // 
        self.button2.Location := new System.Drawing.Point(792, 387);
        self.button2.Name := 'button2';
        self.button2.Size := new System.Drawing.Size(112, 44);
        self.button2.TabIndex := 14;
        self.button2.Text := 'Сброс';
        self.button2.UseVisualStyleBackColor := true;
        self.button2.Click += button2_Click;
        // 
        // button3
        // 
        self.button3.Location := new System.Drawing.Point(688, 108);
        self.button3.Name := 'button3';
        self.button3.Size := new System.Drawing.Size(171, 44);
        self.button3.TabIndex := 23;
        self.button3.Text := 'Поиск по ОЗУ';
        self.button3.UseVisualStyleBackColor := true;
        self.button3.Click += button3_Click;
        // 
        // label1
        // 
        self.label1.Location := new System.Drawing.Point(688, 82);
        self.label1.Name := 'label1';
        self.label1.Size := new System.Drawing.Size(171, 23);
        self.label1.TabIndex := 24;
        self.label1.Text := 'Команды';
        self.label1.TextAlign := System.Drawing.ContentAlignment.TopCenter;
        // 
        // button4
        // 
        self.button4.Location := new System.Drawing.Point(688, 158);
        self.button4.Name := 'button4';
        self.button4.Size := new System.Drawing.Size(171, 44);
        self.button4.TabIndex := 25;
        self.button4.Text := 'Поиск продуктов разработчика за промежуток';
        self.button4.UseVisualStyleBackColor := true;
        self.button4.Click += button4_Click;
        // 
        // button5
        // 
        self.button5.Location := new System.Drawing.Point(688, 208);
        self.button5.Name := 'button5';
        self.button5.Size := new System.Drawing.Size(171, 44);
        self.button5.TabIndex := 26;
        self.button5.Text := 'Показать самые требовательные программы';
        self.button5.UseVisualStyleBackColor := true;
        self.button5.Click += button5_Click;
        // 
        // button6
        // 
        self.button6.Location := new System.Drawing.Point(688, 258);
        self.button6.Name := 'button6';
        self.button6.Size := new System.Drawing.Size(171, 44);
        self.button6.TabIndex := 27;
        self.button6.Text := 'Построить график';
        self.button6.UseVisualStyleBackColor := true;
        self.button6.Click += button6_Click;
        // 
        // Form1
        // 
        self.ClientSize := new System.Drawing.Size(940, 447);
        self.Controls.Add(self.button6);
        self.Controls.Add(self.button5);
        self.Controls.Add(self.button4);
        self.Controls.Add(self.label1);
        self.Controls.Add(self.button3);
        self.Controls.Add(self.button2);
        self.Controls.Add(self.button1);
        self.Controls.Add(self.dataGridView1);
        self.Name := 'Form1';
        self.Text := 'Показать данные';
        (System.ComponentModel.ISupportInitialize(self.dataGridView1)).EndInit();
        self.ResumeLayout(false);
    end;
